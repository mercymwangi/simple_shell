#include "shell.h"


/**
 * parse_cmd - function that determines the type of cmd
 * @cmd: the command to be parsed
 *
 * Return: const representation the type of the command
 * Description -
 * EXTERNAL_CMD (1) for cmds such as /bin/ls
 * INTERNAL_CMD (2) for cmds such as exit, env
 * PATH_CMD (3)for cmds in the PATH such as ls
 * INVALID_CMD (-1) for invalid cmds
 */

int parse_cmd(char *cmd)
{
	int j;
	char *internal_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	for (j = 0; cmd[j] != '\0'; j++)
	{
		if (cmd[j] == '/')
			return (EXTERNAL_CMD);
	}
	for (j = 0; internal_cmd[j] != NULL; j++)
	{
		if (_strcmp(cmd, internal_cmd[j]) == 0)
			return (INTERNAL_CMD);
	}
	/* @evaluate_path - determines if a command is found in the PATH */
	path = evaluate_path(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}

	return (INVALID_CMD);
}

/**
 * exec_cmd - function that executes a cmd based on type
 * @tokenized_cmd: tokenized cmd
 * @type_cmd: type of the command
 *
 * Return: void
 */
void exec_cmd(char **tokenized_cmd, int type_cmd)
{
	void (*function)(char **cmd);

	if (type_cmd == EXTERNAL_CMD)
	{
		if (execve(tokenized_cmd[0], tokenized_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (type_cmd == PATH_CMD)
	{
		if (execve(evaluate_path(tokenized_cmd[0]), tokenized_cmd, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (type_cmd == INTERNAL_CMD)
	{
		function = get_function(tokenized_cmd[0]);
		function(tokenized_cmd);
	}
	if (type_cmd == INVALID_CMD)
	{
		printf(name_of_shell, STDERR_FILENO);
		printf(": 1: ", STDERR_FILENO);
		printf(tokenized_cmd[0], STDERR_FILENO);
		printf(": cmd not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 *evaluate_path - function that evaluates cmd is in the PATH
 * @cmd: cmd to be used
 *
 * Return: path of the cmd, NULL if not found
 */
char *evaluate_path(char *cmd)
{
	char **path_array = NULL;
	char *tmp, *tmp2, *path_cp;
	char *path = _getenv("PATH");
	int j;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cp = malloc(sizeof(*path_cp) * (_strlen(path) + 1));
	_strcpy(path, path_cp);
	path_array = tokenizer(path_cp, ":");
	for (j = 0; path_array[j] != NULL; j++)
	{
		tmp2 = _strcat(path_array[j], "/");
		tmp = _strcat(tmp2, cmd);
		if (access(tmp, F_OK) == 0)
		{
			free(tmp2);
			free(path_array);
			free(path_cp);
			return (tmp);
		}
		free(tmp);
		free(tmp2);
	}
	free(path_cp);
	free(path_array);
	return (NULL);
}

/**
 * get_function - retrieves a function based on the cmd
 * @cmd: stg to be checked
 *
 * Return: ptr to the correct function, or null on fail
 */
void (*get_function(char *cmd))(char **)
{
	int j;
	function_map[] = {
		{"env", env}, {"exit", exit}
	};

	for (j = 0; j < 2; j++)
	{
		if (_strcmp(cmd, map[j].cmd_name) == 0)
			return (map[j].function);
	}
	return (NULL);
}

/**
 * _getenv - function that gets the env variable
 * @name: name of the env variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	char **my_env;
	char *joint_ptr;
	char *name_cp;

	for (my_env = environ; *my_env != NULL; my_env++)
	{
		for (joint_ptr = *my_env, name_cp = name;
		     *joint_ptr == *name_cp; joint_ptr++, name_cp++)
		{
			if (*joint_ptr == '=')
				break;
		}
		if ((*joint_ptr == '=') && (*name_cp == '\0'))
			return (joint_ptr + 1);
	}
	return (NULL);
}
