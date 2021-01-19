#!/usr/bin/python3
"""
Rotate 2D matrix
"""


def rotate_2d_matrix(matrix):
    """ function that rotates the matrix"""
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix)):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(len(matrix)):
        matrix[i].reverse()
