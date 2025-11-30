"""
Module for calculating the maximum number of unique suggestions
from two lists of items.
"""

import sys

def solve():
    """
    Reads input, processes each test case, and prints the maximum number
    of unique suggestions possible from two lists.
    """
    read_input = sys.stdin.read
    data = read_input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n, m = map(int, data[idx:idx + 2])
        idx += 2
        a = list(map(int, data[idx:idx + n]))
        idx += n
        b = list(map(int, data[idx:idx + m]))
        idx += m
        set_a = set(a)
        set_b = set(b)
        common = set_a & set_b
        max_suggestions = n + m - len(common)
        print(max_suggestions)

if __name__ == "__main__":
    solve()
