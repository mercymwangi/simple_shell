#include "shell.h"

/**
 **strngcpy - copies a string
 *@dest: the destination string copied
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: concatenated string
 */

char *strngcpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **strngcat - concatenate two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to use
 *Return: the concatenated string
 */

char *strngcat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

