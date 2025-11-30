"""
Solution for the problem using frequency grouping logic.
"""

import sys
from collections import defaultdict, Counter


def solve() -> None:
    """Reads input, processes test cases, and prints results."""
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    idx = 1
    out_lines = []

    for _ in range(t):
        n = data[idx]
        idx += 1

        b = data[idx: idx + n]
        idx += n

        freq = Counter(b)

        # Check if reconstruction is possible
        if not all(cnt % val == 0 for val, cnt in freq.items()):
            out_lines.append("-1")
            continue

        # Map each value to list of its positions
        pos_map = defaultdict(list)
        for i, val in enumerate(b):
            pos_map[val].append(i)

        a = [0] * n
        cur_val = 1

        # Assign groups
        for val, positions in pos_map.items():
            step = val
            length = len(positions)

            for start in range(0, length, step):
                group = positions[start:start + step]
                for p in group:
                    a[p] = cur_val
                cur_val += 1

        out_lines.append(" ".join(map(str, a)))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    solve()
