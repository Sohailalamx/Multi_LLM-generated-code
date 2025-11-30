"""
Module for solving the divineness tree problem.
Given n nodes and a target divineness m, construct a tree with root 1
such that the total divineness equals m, or return -1 if impossible.
"""

import sys

def solve():
    """
    Reads input, processes each test case, and prints the root and edges
    of the tree with the required divineness, or -1 if impossible.
    """
    read_input = sys.stdin.read
    data = read_input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n, m = map(int, data[idx:idx + 2])
        idx += 2
        if m < n or m > n * (n + 1) // 2:
            print(-1)
            continue

        total_divineness = n * (n + 1) // 2
        if m == total_divineness:
            print(1)
            for i in range(2, n + 1):
                print(f"1 {i}")
            continue

        left, right = 1, n
        answer = -1
        while left <= right:
            mid = (left + right) // 2
            subtree_div = mid * (mid + 1) // 2
            remaining_div = (n - mid) * (mid + 1)
            total = subtree_div + remaining_div
            if total == m:
                answer = mid + 1
                break
            if total < m:
                left = mid + 1
            else:
                right = mid - 1

        if answer == -1:
            print(-1)
        else:
            print(answer)
            for i in range(2, answer + 1):
                print(f"{answer} {i}")
            for i in range(answer + 1, n + 1):
                print(f"{answer} {i}")

if __name__ == "__main__":
    solve()
