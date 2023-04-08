#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to the binary string
 *
 * Return: the converted number, or 0 if there are one or more chars in the
 *         string b that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b == '0' || *b == '1')
		{
			result = (result << 1) | (*b - '0');
			b++;
		}
		else
		{
			return (0);
		}
	}

	return (result);
}
