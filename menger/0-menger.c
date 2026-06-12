#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - prints the 2D Menger Sponge fractal
 * @level: level of the fractal
 *
 * Prints a 2D representation of a Menger Sponge fractal
 * corresponding to the given level.
 */
void menger(int level)
{
	int size;
	int x;
	int y;
	int tx;
	int ty;
	char c;

	if (level < 0)
	{
		return;
	}

	size = pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			c = '#';

			tx = x;
			ty = y;

			while (tx > 0 || ty > 0)
			{
				if (tx % 3 == 1 && ty % 3 == 1)
				{
					c = ' ';
					break;
				}

				ty /= 3;
				tx /= 3;
			}

			printf("%c", c);
		}

		printf("\n");
	}
}
