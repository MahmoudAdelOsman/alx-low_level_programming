#!/usr/bin/python3
""" Island Perimeter"""


def island_perimeter(grid):
    """returns the perimeter of
    the island described in grid"""
    x = len(grid[0])
    y = len(grid)
    a = 0
    c = 0

    for i in range(y):
        for n in range(x):
            if grid[i][n] == 1:
                a += 1
                if n > 0 and grid[i][n - 1] == 1:
                    c += 1
                if i > 0 and grid[i - 1][n] == 1:
                    c += 1
    return a * 4 - c * 2
