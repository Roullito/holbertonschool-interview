def canUnlockAll(boxes):
    """Return True if every box can be opened starting from box 0. Or False if
    not every boxes can be open.
    """
    n = len(boxes)
    opened = {0}
    to_explore = [0]

    while to_explore:
        current_box = to_explore.pop()
        for key in boxes[current_box]:
            if 0 <= key < n and key not in opened:
                opened.add(key)
                to_explore.append(key)

    return len(opened) == n
