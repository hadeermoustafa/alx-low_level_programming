#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - A function that print strings followed by a new line.
 * @separator: An input string to be printed between numbers.
 * @n: number of parameters
 * ap = victor, i = david, string = anataku (Declaration).
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list victor;
	unsigned int david = 0;
	char *anataku;

	va_start(victor, n);
	for (; david < n; david++)
	{
	anataku = va_arg(victor, char*);
	if (anataku == NULL)
		printf("(nil)");
	else
		printf("%s", anataku);
	if (separator == NULL)
		continue;
	if (david < n - 1)
		printf("%s", separator);
	}
	printf("\n");
	va_end(victor);
}
