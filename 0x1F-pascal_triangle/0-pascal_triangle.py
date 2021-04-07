#!/usr/bin/python3
"""
pascals triangle
"""
def pascal_triangle(n):
    """
    Returns a list of integers representing Pascal's triangle
    """
    arr = [[] for x in range(0, n)]
    for x in range(0, n):
        for y in range(x+1):
            if ( y < x):
                if (y <= 0):
                    arr[x].append(1)
                else:
                    arr[x].append(arr[x - 1][y] + arr[x - 1][y - 1])
            elif (x == y):
                arr[x].append(1)
    return (arr)
