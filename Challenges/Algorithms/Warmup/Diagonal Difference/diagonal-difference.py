#!/bin/python3

import sys


n = int(input().strip())
a = []
for a_i in range(n):
    a_t = [int(a_temp) for a_temp in input().strip().split(' ')]
    a.append(a_t)

# Matrix State Variables
sum_diagonal_primary = 0
sum_diagonal_secondary = 0
current_column_primary = 0
current_column_secondary = n - 1

for row in a:
    for column_index, value in enumerate(row):

        # Check the Primary Diagonal
        if column_index == current_column_primary:
            sum_diagonal_primary += value

        # Check the Secondary Diagonal
        if column_index == current_column_secondary:
            sum_diagonal_secondary += value

    # Advance to the Next Row
    current_column_primary += 1
    current_column_secondary -= 1

print(abs(sum_diagonal_primary - sum_diagonal_secondary))
