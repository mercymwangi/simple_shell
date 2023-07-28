#include "shell.h"

/**
 * tokenizer - function that tokenizes input into an array
 * @str_input: input to be tokenized
 * @del: the delimiter to be used
 *
 * Return: array of tokens
 */

char **tokenizer(char *str_input, char *del)
{
	int del_num = 0;
	char **av = NULL;
	char *token = NULL;
	char *std_ptr = NULL;

	token = _strtok_r(str_input, del, &std_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * del_num, sizeof(*av) * (del_num + 1));
		av[del_num] = token;
		token = _strtok_r(NULL, del, &std_ptr);
		del_num++;
	}

	av = _realloc(av, sizeof(*av) * del_num, sizeof(*av) * (del_num + 1));
	av[del_num] = NULL;

	return (av);
}

/**
 * std_output - function that prints a string to stdout
 * @str: the string to print
 * @stream: the stream to print out to
 *
 *Return: void, return nothing
 */
void std_output(char *str, int stream)
{
	int j = 0;

	for (; str[j] != '\0'; j++)
		write(stream, &str[j], 1);
}

/**
 * delete_newline - function that removes new line from a string
 * @str: the string to be used
 *
 *Return: void
 */

void delete_newline(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			break;
		i++;
	}
	str[j] = '\0';
}

/**
 * _strcpy -function that copies a string to another buffer
 * @str: source to copy from
 * @dest: destination to copy to
 *
 * Return: void
 */

void _strcpy(char *str, char *dest)
{
	int j = 0;

	for (; str[j] != '\0'; i++)
		dest[j] = str[j];
	dest[j] = '\0';
}

/**
 * _strlen - function that counts string length
 * @str: the string to be counted
 *
 * Return: length of the str
 */

int _strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (length);
	for (; str[length] != '\0'; length++)
		;
	return (length);
}
