#!/bin/python3

import sys


n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]

positives = 0
negatives = 0
zeroes = 0

for number in arr:
    if number < 0:
        negatives += 1
    elif number > 0:
        positives += 1
    elif number == 0:
        zeroes += 1

print(positives / n)
print(negatives / n)
print(zeroes / n)
