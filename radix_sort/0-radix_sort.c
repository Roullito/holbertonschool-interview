#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the maximum value in an array
 * @array: Array to search
 * @size: Number of elements in the array
 *
 * Return: Maximum value found
 */
static int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * reset_count - Resets a base-10 counting array
 * @count: Counting array to reset
 */
static void reset_count(size_t *count)
{
	size_t i;

	for (i = 0; i < 10; i++)
		count[i] = 0;
}

/**
 * radix_counting_sort - Sorts an array by one significant digit
 * @array: Array to sort
 * @output: Temporary output buffer
 * @size: Number of elements in the array
 * @digit: Current significant digit
 */
static void radix_counting_sort(int *array, int *output,
	size_t size, size_t digit)
{
	size_t i, current;
	size_t count[10];

	reset_count(count);
	for (i = 0; i < size; i++)
	{
		current = (array[i] / digit) % 10;
		count[current]++;
	}
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	i = size;
	while (i > 0)
	{
		i--;
		current = (array[i] / digit) % 10;
		output[count[current] - 1] = array[i];
		count[current]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of non-negative integers in ascending order
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	size_t max, digit;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	if (max == 0)
		return;

	output = malloc(sizeof(*output) * size);
	if (output == NULL)
		return;

	for (digit = 1; max / digit > 0; digit *= 10)
	{
		radix_counting_sort(array, output, size, digit);
		print_array(array, size);
		if (max / digit < 10)
			break;
	}

	free(output);
}
