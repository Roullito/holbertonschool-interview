#!/usr/bin/python3
"""Rotate an n x n matrix 90 degrees clockwise."""


def rotate_2d_matrix(matrix):
    """Rotate a square 2D matrix 90 degrees clockwise in place."""
    size = len(matrix)

    for row in range(size):
        for col in range(row + 1, size):
            matrix[row][col], matrix[col][row] = (
                matrix[col][row], matrix[row][col])

    for row in range(size):
        matrix[row].reverse()
