#!/bin/python3

import sys

def birthdayCakeCandles(n, ar):
    # Most interviewers probably think this is cheating.
    return ar.count(max(ar))

    # In which case, something like this might be more expected:
    max_value = 0
    count = 0
    for i in ar:
        if i > max_value:
            max_value = i

    for i in ar:
        if i == max_value:
            count += 1

    return count


n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = birthdayCakeCandles(n, ar)
print(result)
