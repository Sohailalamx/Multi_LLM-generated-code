"""
Compute the required answer based on set intersections for multiple test cases.
"""

import sys


def solve() -> None:
    """Reads input, processes each test case, and prints results."""
    data = sys.stdin.read().strip().split()
    if not data:
        return

    it = iter(data)
    t = int(next(it))
    out_lines = []

    for _ in range(t):
        n = int(next(it))
        m = int(next(it))

        a_set = {int(next(it)) for _ in range(n)}
        b_set = {int(next(it)) for _ in range(m)}

        inter = a_set & b_set

        x = len(a_set) - len(inter)   # |A \ B|
        y = len(b_set) - len(inter)   # |B \ A|

        if x == y:
            ans = 2 * x + 1
        elif x < y:
            ans = 2 * x + 1
        else:
            ans = 2 * y + 2

        out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    solve()
