#include "search_algos.h"

/**
 * print_search - Prints the array range being searched
 * @array: Pointer to the first element of the array
 * @start: First index of the range
 * @end: Last index of the range
 */
static void print_search(int *array, size_t start, size_t end)
{
	size_t index;

	printf("Searching in array: ");
	index = start;
	while (index <= end)
	{
		printf("%d", array[index]);
		if (index < end)
			printf(", ");
		index++;
	}
	printf("\n");
}

/**
 * binary_search - Searches recursively for the first occurrence of a value
 * @array: Pointer to the first element of the array
 * @start: First index of the range
 * @end: Last index of the range
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1
 */
static int binary_search(int *array, size_t start, size_t end, int value)
{
	size_t middle;

	if (start > end)
		return (-1);

	print_search(array, start, end);
	if (start == end)
	{
		if (array[start] == value)
			return ((int)start);
		return (-1);
	}

	middle = start + (end - start) / 2;

	if (array[middle] == value &&
	    (middle == start || array[middle - 1] != value))
		return ((int)middle);

	if (array[middle] >= value)
		return (binary_search(array, start, middle, value));

	return (binary_search(array, middle + 1, end, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}
