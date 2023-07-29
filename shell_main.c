#include "shell.h"

/**
 * main - main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: 0 on success
 */

	char **commands = NULL;
	char *line = NULL;
	char *shell_name = NULL;
	int status = 0;


int main(int argc __attribute__((unused)), char **argv)
{
<<<<<<< HEAD
	char **current_cmd = NULL, **cmds; 
	char *input; char *name_of_shell = NULL;
	int j, cmd_type = 0, status = 0;
=======
	char **current_command = NULL;
	int i, type_command = 0;
>>>>>>> 7bf2dcad86d38724c4e5a4b506cc0835ca3a14f3
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
<<<<<<< HEAD
		printf("%d #cisfun$ ", STDOUT_FILENO);
		if (getline(&input, &n, stdin) == -1)
=======
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
>>>>>>> 7bf2dcad86d38724c4e5a4b506cc0835ca3a14f3
		{
			free(line);
			exit(status);
		}
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");

		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);

			/* initializer -   */
			initializer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);

	return (status);
}
