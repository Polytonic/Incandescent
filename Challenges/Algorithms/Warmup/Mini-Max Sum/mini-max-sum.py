#!/bin/python3

import sys

arr = list(map(int, input().strip().split(' ')))

sum_min = 0
sum_max = 0
arr = sorted(arr)
for index, value in enumerate(arr):
    if index < 4: sum_min += value
    if index > 0: sum_max += value

print(str(sum_min) + " " + str(sum_max))
