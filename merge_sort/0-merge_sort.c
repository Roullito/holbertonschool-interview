#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy_values - Copies merged values back into the array
 * @array: Array to receive sorted values
 * @buffer: Buffer containing sorted values
 * @size: Number of elements to copy
 */
static void copy_values(int *array, int *buffer, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * merge_arrays - Merges two sorted sub-arrays
 * @array: Array containing the sub-arrays
 * @buffer: Temporary buffer
 * @left_size: Size of the left sub-array
 * @right_size: Size of the right sub-array
 */
static void merge_arrays(int *array, int *buffer,
	size_t left_size, size_t right_size)
{
	size_t left, right, index;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, left_size);
	printf("[right]: ");
	print_array(array + left_size, right_size);

	left = 0;
	right = 0;
	index = 0;
	while (left < left_size && right < right_size)
	{
		if (array[left] <= array[left_size + right])
			buffer[index++] = array[left++];
		else
			buffer[index++] = array[left_size + right++];
	}
	while (left < left_size)
		buffer[index++] = array[left++];
	while (right < right_size)
		buffer[index++] = array[left_size + right++];

	copy_values(array, buffer, left_size + right_size);
	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort_recursive - Sorts an array using top-down merge sort
 * @array: Array to sort
 * @buffer: Temporary buffer
 * @size: Number of elements in the array
 */
static void merge_sort_recursive(int *array, int *buffer, size_t size)
{
	size_t left_size, right_size;

	if (size < 2)
		return;

	left_size = size / 2;
	right_size = size - left_size;

	merge_sort_recursive(array, buffer, left_size);
	merge_sort_recursive(array + left_size, buffer, right_size);
	merge_arrays(array, buffer, left_size, right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, size);
	free(buffer);
}
