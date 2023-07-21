#include <stdio.h>
#include "shell.h"

/**
 * my_main - entry point
 *
 * Return: 0 Always (success)
 */
int my_main(void)
{
	int a = 10;
	int b = 15;

	int sum = (a + b);

	printf("Result: %d\n", sum);

	return (0);
}
