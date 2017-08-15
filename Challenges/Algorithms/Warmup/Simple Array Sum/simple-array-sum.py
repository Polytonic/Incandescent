#!/bin/python3

import sys

def simpleArraySum(n, ar):
    # See Also: sum()
    sum = 0
    for number in ar:
        sum += number
    return sum


n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = simpleArraySum(n, ar)
print(result)
