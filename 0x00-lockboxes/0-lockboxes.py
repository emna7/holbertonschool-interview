#!/usr/bin/python3
def canUnlockAll(boxes):
    """check if all boxes can be opened"""
    try:
        keys = [0] + [i for i in boxes[0]]
    except:
        return False
    can_unlock = [False for i in boxes]
    try:
        for i in range(len(boxes)):
            if can_unlock[i] is False or i == 0:
                if i in keys:
                    can_unlock[i] = True
                    for k in boxes[i]:
                        if k not in keys:
                            keys += [k]
                    for j in boxes[i]:
                        for k in boxes[j]:
                            if k not in keys:
                                keys += [k]
                else:
                    can_unlock[i] = False
    except:
        pass
    return all(can_unlock)
