#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to inspect
 * @accept: accepted characters
 *
 * Return: number of bytes in the initial segment of s made only of accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;
	unsigned int j;
	int found;

	while (s[i] != '\0')
	{
		found = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
			break;
		i++;
	}

	return (i);
}
