#include "shell.h"

/**
 * current_env - function that prints the current environment
 * @tokenized_command: command to be tokenized
 *
 * Return: void
 */

void current_env(char **tokenized_command __attribute__((unused)))
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		print(environ[j], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * exit - function that exits the shell
 * @tokenized_command: command to be tokenized
 *
 * Return: void
 */

void exit(char **tokenized_command)
{
	int num_tok = 0, arg;

	for (; tokenized_command[num_tok] != NULL; num_tok++)
		;
	if (num_tok == 1)
	{
		free(tokenized_command);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_tok == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			print(name_of_shell, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_command[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_command);
			free(commands);
			exit(arg);
		}
	}
	else
		print("$: exit takes only one argument\n", STDERR_FILENO);
}
