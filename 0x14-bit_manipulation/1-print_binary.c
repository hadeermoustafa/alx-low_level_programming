#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = (unsigned long int)1 << (sizeof(unsigned long int) * 8 - 1);
	int started = 0;

	while (mask > 0)
	{
		if (n & mask)
		{
			started = 1;
			putchar('1');
		}
		else
		{
			if (started)
			{
				putchar('0');
			}
		}
		mask >>= 1;
	}
	if (!started)
	{
		putchar('0');
	}
}
