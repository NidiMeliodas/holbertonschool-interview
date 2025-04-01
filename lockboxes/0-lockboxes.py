"""
Exercice:
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""

def canUnlockAll(boxes):
    """
    This function will check if all the boxes can be opened using
    a key found in another box.
    """
    if not isinstance(boxes, list):
        return False
    if len(boxes) == 0:
        return False
    
    n = len(boxes)
    opened = {0}  # Start with the first box opened
    keys = set(boxes[0])  # Start with keys from the first box
    
    while keys:
        key = keys.pop()
        if 0 <= key < n and key not in opened:
            opened.add(key)
            keys.update(boxes[key])
    
    return len(opened) == n