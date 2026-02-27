#!/usr/bin/python3
"""Minimum operations module."""


def minOperations(n):
    """Calculate the fewest operations needed to reach exactly n H characters.

    Args:
        n (int): Target number of H characters.

    Returns:
        int: Minimum number of operations, or 0 if impossible.
    """
    operations = 0
    divisor = 2

    if not isinstance(n, int) or n < 2:
        return 0

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
