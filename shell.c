#include "shell.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	char* input = NULL;
	char* prompt = "#cisfun$";
	char* input = NULL, *input_copy = NULL;
	size_t n = 0;
	ssize_t bytes_read;
	char* tok;
	const char *delim = " \n";
	char **argv;
	int j;
	int num_tok = 0;

	printf("%s", prompt);

	bytes_read = getline(&input, &n, stdin);

	if (input_copy == NULL)
	{
		perror("mem allocation error");
		return (-1);
	}
	strcpy(input_copy, input);

	if (bytes_read == -1)
	{
		printf("Exit shell...\n");
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

	tok = strtok(input_copy, delim);

	for (j = 0; tok != NULL; j++)
	{
		argv[j] = malloc(sizeof(char *) * strlen(tok));
		strcpy(argv[j], delim);
		tok = strtok(NULL, delim);
	}
	argv[j] = NULL;

	free(argv);
	free(input);
	free(input_copy);
	}
	return (0);
}
