#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the converted integer, or 0 if no number is found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int n = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 - (s[i] - '0');
		i++;
	}

	if (sign == 1)
		n = -n;

	return (n);
}
