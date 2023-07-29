#include "shell.h"

/**
 * _strcmp - function that compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: difference of the two strings
 */

int _strcmp(char *str1, char *str2)
{
	int j = 0;

	while (str1[j] != '\0')
	{
		if (str1[j] != str2[j])
			break;
		j++;
	}
	return (str1[j] - str2[j]);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: string destination
 * @str:  string source
 *
 * Return: the address of new string
 */

char *_strcat(char *dest, char *str)
{
	char *new_str =  NULL;
	int length_dest = _strlen(dest);
	int length_str = _strlen(str);

	new_str = malloc(sizeof(*new_str) * (length_dest + length_str + 1));
	_strcpy(dest, new_str);
	_strcpy(str, new_str + length_dest);
	new_str[length_dest + length_str] = '\0';
	return (new_str);
}

/**
 * _strspn - function that gets the length of a prefix substring
 * @string1: string searched
 * @string2: string used
 *
 * Return: number of bytes in the initial segment
 */

int _strspn(char *string1, char *string2)
{
	int j = 0;
	int match = 0;

	while (string1[j] != '\0')
	{
		if (_strchr(string2, string1[j]) == NULL)
			break;
		match++;
		j++;
	}
	return (match);
}

/**
 * _strcspn -function that computes segment of str1 which are not in str2
 * @string1: string searched
 * @string2: string used
 *
 * Return: index of char in str1 exists in str2
 */

int _strcspn(char *string1, char *string2)
{
	int length = 0, j;

	for (j = 0; string1[j] != '\0'; j++)
	{
		if (_strchr(string2, string1[j]) != NULL)
			break;
		length++;
	}
	return (length);
}

/**
 * _strchr - function that finds a character in a string
 * @str: string searched
 * @c: character to be checked
 *
 * Return: pointer to occurence of character in string
 */

char *_strchr(char *str, char c)
{
	int j = 0;

	for (; str[j] != c && str[j] != '\0'; j++)
		;
	if (str[j] == c)
		return (str + j);
	else
		return (NULL);
}
