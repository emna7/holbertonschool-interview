#!/usr/bin/python3
"""
Minimum operations
"""


def minOperations(n):
    res = 0
    i = 2

    while (i <= n):
        if n % i == 0:
            res = res + i
            n = n / i
        else:
            i += 1

    return res
