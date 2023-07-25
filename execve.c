#include "shell.h"

/**
 * execmd - function that executes a command
 * @argv: an array of strings
 * Return: 0
 */
void execmd(char **argv)
{
	char *cmd = NULL;
	char *real_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		real_cmd = get_path(cmd);


		if (execve(real_cmd, argv, NULL) == -1)
		{
			perror("error found:");
		}
	}
}
