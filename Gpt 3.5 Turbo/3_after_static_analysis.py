"""
Tree construction solution with constrained path sum and label assignments.
"""

import sys


def solve() -> None:
    """Reads input, constructs required tree, and prints edges."""
    data = sys.stdin.read().strip().split()
    if not data:
        return

    it = iter(data)
    t = int(next(it))
    out_lines = []

    for _ in range(t):
        n = int(next(it))
        m = int(next(it))

        max_sum = n * (n + 1) // 2
        if m < n or m > max_sum:
            out_lines.append("-1")
            continue

        # extra = amount exceeding minimal path sum n
        extra = m - n
        rem = extra
        increments = []

        # Choose distinct vals from (n-1 ... 1) to match `extra`
        for v in range(n - 1, 0, -1):
            if v <= rem:
                increments.append(v)
                rem -= v

        # Construct path labels
        path_labels = [1]
        for val in sorted(increments):
            path_labels.append(val + 1)

        k = len(path_labels)
        used_labels = set(path_labels)

        # Remaining labels in ascending order
        remaining_labels = [
            lbl for lbl in range(2, n + 1) if lbl not in used_labels
        ]

        # Assign node ids in order
        id_map = {}
        node_id = 1

        for lbl in path_labels:
            id_map[node_id] = lbl
            node_id += 1

        for lbl in remaining_labels:
            id_map[node_id] = lbl
            node_id += 1

        # Build edges
        edges = []

        # Path edges
        for i in range(2, k + 1):
            edges.append((i - 1, i))

        # Attach remaining nodes to root
        for j in range(k + 1, n + 1):
            edges.append((1, j))

        out_lines.append("1")
        for u, v in edges:
            out_lines.append(f"{u} {v}")

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    solve()
