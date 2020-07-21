#!/usr/bin/python3


def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened"""
    if type(boxes) != list:
        return False
    if len(boxes) == 0:
        return False
    else:
        len = len(boxes)
    keys = [0]
    for i in keys:
        for value in boxes[i]:
            if value not in keys:
                if value != i and value != 0 and value < len:
                    keys.append(value)
    if len(keys) == len:
        return True
    else:
        return False
