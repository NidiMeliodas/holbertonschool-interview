#!usr/bin/python3
# Method that determines if all the boxes can be opened.def can_unlock_all(boxes):

def can_unlock_all(boxes):
    """
    Determines if all boxes can be opened.
    
    Args:
        boxes (list of list of int): A list where each index represents a box, 
        and the list at each index contains keys to other boxes.
    
    Returns:
        bool: True if all boxes can be opened, else False.
    """
    n = len(boxes)
    opened = {0}  # Start with the first box opened
    keys = set(boxes[0])  # Start with keys from the first box

    while keys:
        key = keys.pop()  # Take a key
        if key < n and key not in opened:  # Check if it unlocks a new box
            opened.add(key)  # Mark box as opened
            keys.update(boxes[key])  # Add new keys from this box

    return len(opened) == n  # True if all boxes are opened
