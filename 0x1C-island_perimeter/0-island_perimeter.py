#!/usr/bin/python3
"""
island_perimeter function
"""


def island_perimeter(grid):
    """
    returns the perimeter of island in grid
    """
    # Perimeter = number of edges
    # edge detection along horizontal and vertical direction

    def edges(matrix):
        """
        detect number of edges along horizontal direction
        """
        count = 0
        for row in matrix:
            row = [0] + row + [0]
            for i in range(1, len(row)):
                count += row[i] != row[i-1]
            # print(count)
        return count

    tgrid = [[] for _ in range(len(grid[0]))]  # tranposed matrix
    for row in grid:
        for i, item in enumerate(row):
            tgrid[i].append(item)

    return edges(grid) + edges(tgrid)
