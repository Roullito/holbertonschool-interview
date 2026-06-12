#include <stdio.h>
#include "slide_line.h"

/**
 * compact_left - move all non-zero values to the left
 * @line: pointer to the array
 * @size: size of the array
 *
 * Return: void
 */
static void compact_left(int *line, size_t size)
{
	size_t read;
	size_t write;

	write = 0;

	for (read = 0; read < size; read++)
	{
		if (line[read] != 0)
		{
			line[write] = line[read];
			write++;
		}
	}

	while (write < size)
	{
		line[write] = 0;
		write++;
	}
}

/**
 * compact_right - Moves all non-zero values to the right.
 * @line: Array of integers to compact.
 * @size: Number of elements in the array.
 *
 * All non-zero values are shifted toward the end of the array
 * while preserving their relative order. Remaining positions are
 * filled with zeros.
 */
static void compact_right(int *line, size_t size)
{
	int read;
	int write;

	write = size - 1;

	for (read = size - 1; read >= 0; read--)
	{
		if (line[read] != 0)
		{
			line[write] = line[read];
			write--;
		}
	}

	while (write >= 0)
	{
		line[write] = 0;
		write--;
	}
}

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Array of integers to process.
 * @size: Number of elements in the array.
 * @direction: Direction of the slide operation.
 *
 * Slides the array either to the left or to the right and merges
 * adjacent identical values according to the rules of the 2048 game.
 *
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT)
	{
		compact_left(line, size);

		for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}

		compact_left(line, size);
		return (1);
	}

	if (direction == SLIDE_RIGHT)
	{
		compact_right(line, size);

		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}

		compact_right(line, size);
		return (1);
	}

	return (0);
}
