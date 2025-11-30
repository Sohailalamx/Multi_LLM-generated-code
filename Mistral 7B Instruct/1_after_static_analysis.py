"""
Module for solving the permutation frequency problem.
"""

import sys

def solve():
    """
    Solves the permutation frequency problem.
    Reads input, processes each test case, and prints the result.
    """
    read_input = sys.stdin.read
    data = read_input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        b = list(map(int, data[idx:idx + n]))
        idx += n
        freq = {}
        for num in b:
            freq[num] = freq.get(num, 0) + 1
        max_freq = max(freq.values())
        if max_freq > n:
            print(-1)
            continue

        assigned = set()
        a = []
        sorted_freq = sorted(freq.items(), key=lambda x: -x[1])

        for num, count in sorted_freq:
            current_num = 1
            while current_num in assigned or current_num > n:
                current_num += 1
            for _ in range(count):
                a.append(current_num)
            assigned.add(current_num)

        if len(a) != n:
            print(-1)
        else:
            print(' '.join(map(str, a)))

if __name__ == "__main__":
    solve()
