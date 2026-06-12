#!/usr/bin/python3
"""Solve the N queens puzzle."""

import sys


def is_safe(solution, row, col):
    """Return True if a queen can be placed at row, col."""
    for queen_row, queen_col in solution:
        if queen_col == col:
            return False
        if abs(queen_row - row) == abs(queen_col - col):
            return False

    return True


def solve_nqueens(n, row, solution):
    """Print every solution for an n by n chessboard."""
    if row == n:
        print(solution)
        return

    for col in range(n):
        if is_safe(solution, row, col):
            solution.append([row, col])
            solve_nqueens(n, row + 1, solution)
            solution.pop()


def main():
    """Validate arguments and start the solver."""
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

    solve_nqueens(n, 0, [])


if __name__ == "__main__":
    main()
