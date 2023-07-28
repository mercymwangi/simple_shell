#include "shell.h"

/**
 * current_env - function that prints the current environment
 * @tokenized_cmd: command to be tokenized
 *
 * Return: void
 */

void current_env(char **tokenized_cmd)
{
	int j;
	tokenized_cmd(void);

	for (j = 0; environ[j] != NULL; j++)
	{
		printf(environ[j], STDOUT_FILENO);
		printf("\n", STDOUT_FILENO);
	}
}

/**
 * exit - function that exits the shell
 * @tokenized_cmd: command to be tokenized
 *
 * Return: void
 */

void exit(char **tokenized_cmd)
{
	int num_tok = 0, arg;

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
			printf(name_of_shell, STDERR_FILENO);
			printf(": 1: exit: number not allowed: ", STDERR_FILENO);
			printf(tokenized_cmd[1], STDERR_FILENO);
			printf("\n", STDERR_FILENO);
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
