#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another.
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits required to flip to get from n to m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit_diff = n ^ m;
	unsigned int count = 0;

	while (bit_diff != 0)
	{
		if ((bit_diff & 1) == 1) /* check if the rightmost bit is 1 */
			count++;

		bit_diff = bit_diff >> 1; /* shift right to check the next bit */
    }

	return (count);
}
