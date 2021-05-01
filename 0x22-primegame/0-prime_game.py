#!/usr/bin/python3
"""Module that holds isWinner method"""


def isWinner(x, nums):
    """Function that performs prime game"""
    if not nums or x < 1:
        return None
    n = max(nums)
    y = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not y[i]:
            continue
        for j in range(i * i, n + 1, i):
            y[j] = False
    y[0] = y[1] = False
    count = 0
    for i in range(len(y)):
        if y[i]:
            count += 1
        y[i] = count
    z = 0
    for n in nums:
        z += y[n] % 2 == 1
    if z * 2 == len(nums):
        return None
    if z * 2 > len(nums):
        return "Maria"
    return "Ben"
