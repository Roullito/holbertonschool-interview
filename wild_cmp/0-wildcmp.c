#include "holberton.h"

/**
 * wildcmp - Compares two strings, allowing wildcards in the second string
 * @s1: First string to compare
 * @s2: Second string to compare, may contain '*'
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (s1 == 0 || s2 == 0)
		return (0);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0')
			return (wildcmp(s1 + 1, s2));
		return (0);
	}

	if (*s1 == '\0' || *s2 == '\0')
		return (*s1 == *s2);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
