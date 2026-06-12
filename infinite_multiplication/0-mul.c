#include <stdlib.h>
#include "holberton.h"

/**
 * is_digit_string - Checks whether a string contains only digits
 * @str: String to check
 *
 * Return: 1 if the string contains only digits, otherwise 0
 */
int is_digit_string(char *str)
{
	int index;

	if (str == NULL || str[0] == '\0')
		return (0);

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}

	return (1);
}

/**
 * str_len - Computes the length of a string
 * @str: String to measure
 *
 * Return: Length of the string
 */
int str_len(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * print_error - Prints Error and exits with status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * print_result - Prints a multiplication result
 * @result: Array containing the result digits
 * @size: Size of the result array
 */
void print_result(int *result, int size)
{
	int index;
	int started;

	started = 0;
	for (index = 0; index < size; index++)
	{
		if (result[index] != 0 || started || index == size - 1)
		{
			_putchar(result[index] + '0');
			started = 1;
		}
	}
	_putchar('\n');
}

/**
 * multiply - Multiplies two positive numbers stored as strings
 * @num1: First number
 * @num2: Second number
 * @len1: Length of num1
 * @len2: Length of num2
 *
 * Return: Pointer to an array containing the result digits
 */
int *multiply(char *num1, char *num2, int len1, int len2)
{
	int *result;
	int i;
	int j;
	int size;
	int product;

	size = len1 + len2;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		print_error();

	for (i = 0; i < size; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0');
			product += result[i + j + 1];
			result[i + j + 1] = product % 10;
			result[i + j] += product / 10;
		}
	}

	return (result);
}

/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int len1;
	int len2;
	int size;
	int *result;

	if (argc != 3)
		print_error();
	if (!is_digit_string(argv[1]) || !is_digit_string(argv[2]))
		print_error();

	len1 = str_len(argv[1]);
	len2 = str_len(argv[2]);
	size = len1 + len2;
	result = multiply(argv[1], argv[2], len1, len2);
	print_result(result, size);
	free(result);

	return (0);
}
