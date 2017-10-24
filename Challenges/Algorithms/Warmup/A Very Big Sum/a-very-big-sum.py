#!/bin/python3

import sys

def aVeryBigSum(n, ar):
    # This is technically cheating, since Python supports arbitrarily large integers by default.
    return sum(ar)

    # The problem is most likely asking for something along these lines:
    total = 0
    for number in ar:
        total += number
    return total

n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = aVeryBigSum(n, ar)
print(result)
