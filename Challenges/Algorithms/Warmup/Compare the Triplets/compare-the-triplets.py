#!/bin/python3

import sys


def compare(a, b):
    score_player_a = 0
    score_player_b = 0

    if a > b:
        score_player_a += 1
    elif a < b:
        score_player_b += 1

    return score_player_a, score_player_b


def solve(a0, a1, a2, b0, b1, b2):
    first = compare(a0, b0)
    second = compare(a1, b1)
    third = compare(a2, b2)

    score_alice = first[0] + second[0] + third[0]
    score_bob = first[1] + second[1] + third[1]
    return str(score_alice), str(score_bob)


a0, a1, a2 = input().strip().split(' ')
a0, a1, a2 = [int(a0), int(a1), int(a2)]
b0, b1, b2 = input().strip().split(' ')
b0, b1, b2 = [int(b0), int(b1), int(b2)]
result = solve(a0, a1, a2, b0, b1, b2)
print (" ".join(map(str, result)))
