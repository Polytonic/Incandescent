#!/bin/python3

import sys

def timeConversion(s):

    hours = int(s[0:2])
    minutes = int(s[3:5])
    seconds = int(s[6:8])
    meridiem = s[8:len(s)]

    if meridiem == "AM" and hours == 12:
        hours = 0
    elif meridiem == "PM" and hours < 12:
        hours += 12

    return "%02d:%02d:%02d" % (hours, minutes, seconds)

s = input().strip()
result = timeConversion(s)
print(result)
