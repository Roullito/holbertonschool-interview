#!/usr/bin/python3
"""
N Queens puzzle solver.

This program solves the N Queens problem using a backtracking algorithm.
It places N queens on an N x N chessboard so that no two queens attack
each other, and prints all possible solutions.
"""


import sys


def is_safe(row, col):
    """
    Check whether a queen can be placed at a given position.

    A position is considered safe if no previously placed queen shares
    the same column or diagonal with the candidate position.

    Args:
        row (int): Row where the queen is to be placed.
        col (int): Column where the queen is to be placed.

    Returns:
        bool: True if the position is safe, False otherwise.
    """
    for r, c in solutions:
        if c == col:
            return False

        if abs(r - row) == abs(c - col):
            return False

    return True


def solve(row):
    """
    Solve the N Queens puzzle using backtracking.

    The function attempts to place a queen in each column of the current
    row. When a valid position is found, the queen is placed and the
    algorithm recursively proceeds to the next row. If no valid position
    is available, the function backtracks and tries another placement.

    Args:
        row (int): Current row being processed.

    Returns:
        None
    """
    if row == N:
        print(solutions)
        return

    for col in range(N):
        if is_safe(row, col):
            solutions.append([row, col])
            solve(row + 1)
            solutions.pop()


def main():
    """
    Validate command-line arguments and initialize the solver.

    Ensures that:
    - Exactly one argument is provided.
    - The argument is a valid integer.
    - The integer is greater than or equal to 4.

    Returns:
        int: The validated board size.

    Raises:
        SystemExit: If the provided arguments are invalid.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    return n


N = main()
solutions = []
solve(0)
