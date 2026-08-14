#!/usr/bin/python3
"""Pascal triangle generation module."""


def pascal_triangle(n):
    """Return a list of lists representing Pascal's triangle of size n."""
    triangle = []

    if n <= 0:
        return triangle

    for row_index in range(n):
        row = []
        for column in range(row_index + 1):
            if column == 0 or column == row_index:
                row.append(1)
            else:
                previous = triangle[row_index - 1]
                row.append(previous[column - 1] + previous[column])
        triangle.append(row)

    return triangle
