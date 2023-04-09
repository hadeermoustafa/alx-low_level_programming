#include "main.h"

/**
 * get_endianness - checks the endianness.
 * Write a function that checks the endianness.
 * Returns: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	int num = 100;
	char *endian = (char *) &num;

	if (*endian != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
