#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """calculate how much water will be
       retained after rain
    """
    if len(walls) == 0:
        return 0

    res = 0

    for n in range(len(walls)):
        max_left = walls[n]
        for num in range(n):
            max_left = max(max_left, walls[num])
        max_right = walls[n]
        for num in range(n + 1, len(walls)):
            max_right = max(max_right, walls[num])

        res = res + (min(max_left, max_right) - walls[n])

    return res
