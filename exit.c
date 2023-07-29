#include "shell.h"

/**
 * current_env - function that prints current environment
 * @tokenized_cmd: command to be tokenized
 *
 * Return: void
 */

void current_env(char **tokenized_cmd)
{
	int j;
	(void)tokenized_cmd;

	for (j = 0; environ[j] != NULL; j++)
	{
		printf(environ[j], STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * quit_shell - function that exits the shell
 * @tokenized_cmd: command to be tokenized
 *
 * Return: void
 */

void quit_shell(char **tokenized_cmd)
{
	int num_tok = 0, arg;
	int exitStatus = 1;
	char *input = NULL;
	char *cmds = NULL;
	char *name_of_shell = NULL;

	for (; tokenized_cmd[num_tok] != NULL; num_tok++)
		;
	if (num_tok == 1)
	{
		free(tokenized_cmd);
		free(input);
		free(cmds);
		exit(status);
	}
	else if (num_tok == 2)
	{
		arg = _atoi(tokenized_cmd[1]);
		if (arg == -1)
		{
			printf("%s", name_of_shell, STDERR_FILENO);
<<<<<<< HEAD
			printf("%s: 1: exit: number not allowed: ", STDERR_FILENO);
			printf("%d",tokenized_cmd[1], STDERR_FILENO);
			printf("%c\n", STDERR_FILENO);
=======
			dprintf(STDERR_FILENO, ": 1: exit: %d: number not allowed\n", exitStatus);
			printf(tokenized_cmd[1], STDERR_FILENO); 
			dprintf(STDERR_FILENO, "\n");
>>>>>>> 7bf2dcad86d38724c4e5a4b506cc0835ca3a14f3
			status = 2;
		}
		else
		{
			free(input);
			free(tokenized_cmd);
			free(cmds);
			exit(arg);
		}
	}
	else
		printf("$: one argument\n", STDERR_FILENO);
}
