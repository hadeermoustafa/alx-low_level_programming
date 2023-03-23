#include "variadic_functions.h"

/*
Define a function that takes unkown number of args
add them all
then return result into the screen
*/

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int i;
	va_list x;

	va_start (x,n);

	if (n == 0 )
		return (0);

	for (i = 0; i < n; i++)
		sum += va_arg(x, int);
       
	va_end(x);
	
	return (sum);
}
