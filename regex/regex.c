#include "regex.h"

/**
 * char_match - Checks if a character matches a pattern character
 * @character: Character from the string
 * @pattern: Character from the pattern
 *
 * Return: 1 if the characters match, otherwise 0
 */
static int char_match(char character, char pattern)
{
	return (character != '\0' && (pattern == '.' || character == pattern));
}

/**
 * regex_match - Checks whether a pattern matches a string
 * @str: String to scan
 * @pattern: Regular expression pattern
 *
 * Return: 1 if the pattern matches the string, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (str == 0 || pattern == 0)
		return (0);

	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		if (char_match(*str, *pattern))
			return (regex_match(str + 1, pattern));
		return (0);
	}

	if (char_match(*str, *pattern))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
