#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original;
	unsigned long reverse;
	unsigned long digit;

	original = n;
	reverse = 0;

	while (n > 0)
	{
		digit = n % 10;
		reverse = reverse * 10 + digit;
		n = n / 10;
	}

	if (original == reverse)
		return (1);
	return (0);
}

