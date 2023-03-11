#include "main.h"
#include <ctype.h>
/**
 * _islower - check Holberyton
 * @c: input character
 * Description: function uses _putchar function to print
 * alphabet in lowercase 10 times
 * Return: 1 if is lowercase or if is uppercase
 */
int _islower(int c)
{
	if (islower(c))
	{
		return (1);
	}
	return (0);
}
