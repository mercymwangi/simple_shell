#include "shell.h"


/**
 * _strtok_r - function that tokenizes a string
 * @str: string to be parsed
 * @del: delimiter to be used to parse the string
 * @std_ptr: ptr to be used for the next token
 *
 *Return: The next token
 */
char *_strtok_r(char *str, char *del, char **std_ptr)
{
	char *complete;

	if (str == NULL)
		str = *std_ptr;

	if (*str == '\0')
	{
		*std_ptr = str;
		return (NULL);
	}

	str += _strspn(str, del);
	if (*str == '\0')
	{
		*std_ptr = str;
		return (NULL);
	}

	complete = str + _strcspn(str, del);
	if (*complete == '\0')
	{
		*std_ptr = complete;
		return (str);
	}

	*complete = '\0';
	*std_ptr = complete + 1;
	return (str);
}

/**
 * _atoi - function that changes a str to an int
 * @s: the string to change
 *
 * Return: the converted int
 */
int _atoi(char *str)
{
	unsigned int j = 0;

	do {
		if (*str == '-')
			return (-1);
		else if ((*str < '0' || *str > '9') && *str != '\0')
			return (-1);
		else if (*str >= '0'  && *str <= '9')
			j = (j * 10) + (*str - '0');
		else if (j > 0)
			break;
	} while (*str++);
	return (j);
}

/**
 * _realloc - function that reallocates a memory block
 * @ptr: pointer to the memory
 * @initial_sz: size of ptr
 * @current_sz: size of the new memory to be allocated
 *
 * Return: ptr to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int initial_sz, unsigned int current_sz)
{
	void *tmp_block;
	unsigned int j;

	if (ptr == NULL)
	{
		tmp_block = malloc(current_sz);
		return (tmp_block);
	}
	else if (current_sz == initial_sz)
		return (ptr);
	else if (current_sz == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		tmp_block = malloc(current_sz);
		if (tmp_block != NULL)
		{
			for (j = 0; j < min(initial_sz, current_sz); j++)
				*((char *)tmp_block + j) = *((char *)ptr + j);
			free(ptr);
			return (tmp_block);
		}
		else
			return (NULL);

	}
}

/**
 * ctrl_c_cmd - function that handles CTRL-C
 * @signum: signal number
 *
 * Return: void
 */
void ctrl_c_cmd(int signum)
{
	if (signum == SIGINT)
		printf("\n($) ", STDIN_FILENO);
}

/**
 * delete_comment - funtion that ignores everything after a '#' char
 * @input: user  input
 *
 * Return: void
 */
void delete_comment(char *input)
{
	int j = 0;

	if (input[j] == '#')
		input[j] = '\0';
	while (input[j] != '\0')
	{
		if (input[j] == '#' && input[j - 1] == ' ')
			break;
		j++;
	}
	input[j] = '\0';
}
