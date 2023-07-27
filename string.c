#include "shell.h"

/**
 * strlen -length of a string
 * * @s: -string to check
 * Return: integer length of string
 */

int strlen(char *s)
{
	size_t i = 0

	if (s == NULL)
	return (0);
	while (*s++)
	i++;
	return (i);
}

/**
 * strcmp - comparison of two strangs.
 *@s1: - first strang
 *@s2: - second strang
 * Return: null
 */

int strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * start - needle starts with haystack
 * @haystack: string
 * @needle: substring
 * Return: NULL
 */

char *start(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * strcat -  two strings
 * @dest:destination buffer
 * @src: source buffer
 * Return: NULL
 */

char *strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
