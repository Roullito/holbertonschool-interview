#!/usr/bin/python3
"""Island perimeter calculation module."""


def island_perimeter(grid):
    """Return the perimeter of the island described by grid."""
    perimeter = 0

    for row in range(len(grid)):
        for column in range(len(grid[row])):
            if grid[row][column] == 1:
                perimeter += 4
                if row > 0 and grid[row - 1][column] == 1:
                    perimeter -= 2
                if column > 0 and grid[row][column - 1] == 1:
                    perimeter -= 2

    return perimeter
