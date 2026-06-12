#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @first: Pointer to the first integer
 * @second: Pointer to the second integer
 */
static void swap_ints(int *first, int *second)
{
	int tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/**
 * sift_down - Restores the max heap property from a node down
 * @array: Array to sort
 * @size: Full size of the array
 * @root: Index of the root node to sift down
 * @heap_size: Number of elements in the current heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t heap_size)
{
	size_t child, swap;

	while ((root * 2) + 1 < heap_size)
	{
		child = (root * 2) + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 < heap_size && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		swap_ints(array + root, array + swap);
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (array == NULL || size < 2)
		return;

	start = (size - 2) / 2;
	while (1)
	{
		sift_down(array, size, start, size);
		if (start == 0)
			break;
		start--;
	}

	end = size - 1;
	while (end > 0)
	{
		swap_ints(array, array + end);
		print_array(array, size);
		sift_down(array, size, 0, end);
		end--;
	}
}
