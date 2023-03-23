#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - A function that print numbers followed by a new line.
 * @separator: An input string to be printed between numbers.
 * @n: number of parameters
 * @...: Other parameters
 * Return: The of all parameters
 * (victor = i, david = nums
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int victor = 0;
	int david;

	va_start(ap, n);
	for (; victor < n; victor++)
	{
	david = va_arg(ap, int);
		printf("%d", david);
	if (separator == NULL)
		continue;
	if (victor < n - 1)
		printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
