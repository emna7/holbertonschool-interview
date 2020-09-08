#!/usr/bin/python3
"""
    Computes stdin input
"""


import sys


def addFileSize(data):
    return int(data.split()[8])


def codes(data):
    return data.split()[7]

counter = 0
total_size = 0
code_status = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

try:
    for line in sys.stdin:
        counter += 1
        total_size += addFileSize(line)
        code = codes(line)
        if code in code_status:
            code_status[code] += 1
        if counter == 10:
            print("File size: {:d}".format(total_size))
            for code, value in sorted(code_status.items()):
                if value > 0:
                    print("{}: {:d}".format(code, value))
            counter = 0
except Exception:
    pass

finally:
    print("File size: {:d}".format(total_size))
    for code, value in sorted(code_status.items()):
        if value > 0:
            print("{}: {:d}".format(code, value))
    counter = 0
