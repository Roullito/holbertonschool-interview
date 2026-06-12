#!/usr/bin/python3
"""
UTF-8 validation module.

This module provides a function that determines whether
a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Validate a UTF-8 encoding.

    Args:
        data (list): List of integers representing bytes.

    Returns:
        bool: True if the data is a valid UTF-8 encoding,
        False otherwise.
    """
    remaining = 0

    for num in data:
        bits = bin(num & 0xFF)[2:].zfill(8)

        if remaining > 0:
            if not bits.startswith("10"):
                return False
            remaining -= 1

        else:
            if bits.startswith("0"):
                remaining = 0
            elif bits.startswith("110"):
                remaining = 1
            elif bits.startswith("1110"):
                remaining = 2
            elif bits.startswith("11110"):
                remaining = 3
            else:
                return False

    return remaining == 0
