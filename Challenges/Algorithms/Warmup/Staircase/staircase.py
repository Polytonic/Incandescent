#!/bin/python3

import sys


n = int(input().strip())

# Track Staircase State
num_spaces = n - 1;
num_hashes = 1;

# Iteratively Construct/Print Staircase
for row in range(n):

    # Print Spaces
    for i in range(num_spaces):
        print(" ", end="")
    num_spaces -= 1

    # Print Hashes
    for i in range(num_hashes):
        print("#", end="")
    num_hashes += 1

    # Advance to Next Row
    print("")
