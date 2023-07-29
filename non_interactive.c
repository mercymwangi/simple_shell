#include "shell.h"

/**
 * non_interactive - function that executes in interactive mode
 *
 * Return: void
 */

void non_interactive(void)
{
	char **current_cmd = NULL;
	int j, cmd_type = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&input, &n, stdin) != -1)
		{
			delete_newline(input);
			delete_comment(input);
			cmds = tokenizer(input, ";");
			for (j = 0; cmds[j] != NULL; j++)
			{
				current_cmd = tokenizer(cmds[j], " ");
				if (current_cmd[0] == NULL)
				{
					free(current_cmd);
					break;
				}
				cmd_type = parse_cmd(current_cmd[0]);
				init(current_cmd, cmd_type);
				free(current_cmd);
			}
			free(cmds);
		}
		free(input);
		exit(status);
	}
}
