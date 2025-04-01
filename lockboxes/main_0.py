#!/usr/bin/python3
#tsetttt
"""
    Determines if all boxes can be opened.
    
    Args:
        boxes (list of list of int): A list where each index represents a box, 
        and the list at each index contains keys to other boxes.
    
    Returns:
        bool: True if all boxes can be opened, else False.
    """
canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))
