#include "shell.h"

/**
 * get_path - function that gets the current environment
 * @cmd: the user command
 * Return: 0
 */
char *get_path(char *cmd)
{
	char *path, *path_cp, *path_tok, *full_path;
	int cmd_length, dir_length;
	struct stat buf;

	path = getenv("PATH");

	if (path)
	{
		path_cp = strdup(path);
		cmd_length = strlen(cmd);
		path_tok = strtok(path_cp, ":");

		while (path_tok != NULL)
		{
			dir_length = strlen(path_tok);
			full_path = malloc(cmd_length + dir_length + 2);
			strcpy(full_path, path_tok);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			strcat(full_path, "\0");

			if (stat(full_path, &buf) == 0)
			{
				free(path_cp);
				return (full_path);
			}
			else
			{
				free(full_path);
				path_tok = strtok(NULL, ":");
			}
		}
		free(path_cp);
		if (stat(cmd, &buf) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
