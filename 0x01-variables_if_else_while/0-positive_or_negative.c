#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

/**
 * main - determine if number is positive or negative
 *
 * Description: program will assign a random number to the variable n each time
 *
 * it is executed.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{
		printf( n, "is positive");
	}
	else if (n < 0)
	{
		printf( n, "is negative");
	}
	else
	{
		printf( n, "is zero");
	}

	return (0);
}
