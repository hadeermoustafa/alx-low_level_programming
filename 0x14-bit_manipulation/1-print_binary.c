#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	unsigned int bit = sizeof(n) * 8;

	while (bit--)
	{
		if ((mask << bit) & n)
			_putchar('1');
		else
			_putchar('0');
	}
}
