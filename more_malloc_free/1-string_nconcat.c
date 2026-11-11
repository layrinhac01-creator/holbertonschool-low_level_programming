#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to use
 *
 * Return: pointer to the new string, or NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *res;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	res = malloc(sizeof(char) * (len1 + n + 1));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];
	res[i + j] = '\0';

	return (res);
}
