#include "shell.h"

/**
 * init - function that executes all commands
 * @current_cmd: provides the current token
 * @cmd_type: parses or token str
 *
 * Return: void function
 */

void init(char **current_cmd, int cmd_type)
{
	pid_t PID;

	if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
	{
		PID = fork();

		if (PID == 0)
			exec_cmd(current_cmd, cmd_type);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		exec_cmd(current_cmd, cmd_type);
}
