#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 * @grid: Grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != 0)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a 3x3 sandpile is stable
 * @grid: Grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple_once - Performs one toppling round on a 3x3 sandpile
 * @grid: Grid to topple
 */
static void topple_once(int grid[3][3])
{
	int i, j;
	int next[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			next[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] <= 3)
				continue;

			next[i][j] -= 4;
			if (i > 0)
				next[i - 1][j] += 1;
			if (i < 2)
				next[i + 1][j] += 1;
			if (j > 0)
				next[i][j - 1] += 1;
			if (j < 2)
				next[i][j + 1] += 1;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = next[i][j];
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left-hand stable grid and result grid
 * @grid2: Right-hand stable grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple_once(grid1);
	}
}
