#!/usr/bin/python3
"""Minimum coin change module."""


def makeChange(coins, total):
    """Return the fewest coins needed to meet total."""
    if total <= 0:
        return 0

    coins = sorted(set(coin for coin in coins if coin <= total))
    if not coins:
        return -1

    minimum = [0] + [total + 1] * total

    for amount in range(1, total + 1):
        for coin in coins:
            if coin > amount:
                break
            count = minimum[amount - coin] + 1
            if count < minimum[amount]:
                minimum[amount] = count

    if minimum[total] == total + 1:
        return -1
    return minimum[total]
