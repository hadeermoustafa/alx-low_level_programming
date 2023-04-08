#include "main.h"

int get_endianness(void)
{
	unsigned int num = 1;
	char *endian = (char *)&num;

	if (*endian == 1)
	{
		// Little endian
		return (1);
	}
	else
	{
		// Big endian
		return (0);
	}
}
