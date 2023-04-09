#include "main.h"

/**
 * Write a function that checks the endianness.
 * Returns: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int num = 1;
	char *endian = (char *) &num;

	if (*endian != 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
