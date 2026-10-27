#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @n: The number
 *
 * Return: The value of the last digit
 */
int print_last_digit(int n)
{
	int d;

	d = n % 10;
	if (d < 0)
		d = -d;
	_putchar(d + '0');
	return (d);
}
