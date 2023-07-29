#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments to be parsed
 *
 * Return: 0 on success
 */


int main(int argc, char **argv[])
{
	char **current_cmd = NULL, **cmds; 
	char *input; char *name_of_shell = NULL;
	int j, cmd_type = 0, status = 0;
	size_t n = 0;

	(void)argc;

	signal(SIGINT, ctrl_c_cmd);
	name_of_shell = argv[0];
	while (1)
	{
		non_interactive();
		printf("%d #cisfun$ ", STDOUT_FILENO);
		if (getline(&input, &n, stdin) == -1)
		{
			free(input);
			exit(status);
		}
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

			/* init -   */
			init(current_cmd, cmd_type);
			free(current_cmd);
		}
		free(cmds);
	}
	free(input);

	return (status);
}
