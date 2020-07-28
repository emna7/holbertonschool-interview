#!/usr/bin/python3
"""unlock boxes"""

def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened"""
    if not isinstance(boxes, list) or not len(boxes):
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
