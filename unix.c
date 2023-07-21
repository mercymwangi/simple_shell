#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 Always Success
 */
int main(void)
{
	char *prompt = "#cisfun$";
	char *input = NULL, *input_copy = NULL;
	size_t n = 0;
	ssize_t bytes_read;
	char *tok;
	const char *delim = " \n";
	char **argv;
	int j;
	int num_tok = 0;

	while (1)
	{
		printf("%s", prompt);
		bytes_read = getline(&input, &n, stdin);
		printf("%s\n", input);
		
		if (bytes_read == -1)
		{
			printf("Exit shell...\n");
			free(input);
			free(input_copy);
			return (-1);
		}
	}

	if (input_copy == NULL)
	{
		perror("mem allocation error");
		return (-1);
	}
	input_copy = malloc(sizeof(char) * (strlen(input) + 1));
	strcpy(input_copy, input);
	if (input_copy == NULL)
	{
		perror("mem allocation error");
		free(input);
		return (-1);
	}
	else
	{
		tok = strtok(input, delim);
		while (tok != NULL)
		{
			num_tok++;
			tok = strtok(NULL, delim);
		}
		num_tok++;
		argv = malloc(sizeof(char *) * num_tok);
		if (argv == NULL)
		{
			perror("mem allocation error");
			free(input);
			free(input_copy);
			return (-1);
		}
		tok = strtok(input_copy, delim);
		for (j = 0; tok != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * (strlen(tok) + 1));
			if (argv[j] == NULL)
			{
				perror("mem allocation error");

				free(argv);
				free(input);
				free(input_copy);
				return (-1);
			}
			strcpy(argv[j], tok);
			tok = strtok(NULL, delim);
		}
		argv[j] = NULL;

		free(argv);
		free(input);
		free(input_copy);
	}
	return (0);
}
