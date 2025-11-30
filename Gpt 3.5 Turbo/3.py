
import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out_lines = []
    for _ in range(t):
        n = int(next(it)); m = int(next(it))
        max_sum = n * (n + 1) // 2
        if m < n or m > max_sum:
            out_lines.append("-1")
            continue
        # Construct labels
        extra = m - n  # how much above minimal
        yi = []
        rem = extra
        for v in range(n - 1, 0, -1):
            if v <= rem:
                yi.append(v)
                rem -= v
        # yi now contains distinct positive ints summing to extra
        path_labels = [1]
        for val in sorted(yi):
            path_labels.append(val + 1)
        k = len(path_labels)          # nodes on the main path
        used_labels = set(path_labels)
        # Remaining labels
        remaining_labels = [lbl for lbl in range(2, n + 1) if lbl not in used_labels]
        node_id = 1
        id_map = {}  # node id -> label
        # assign ids to path nodes
        for lbl in path_labels:
            id_map[node_id] = lbl
            node_id += 1
        # assign ids to remaining nodes
        for lbl in remaining_labels:
            id_map[node_id] = lbl
            node_id += 1
        # Build edges
        edges = []
        # Path edges
        for i in range(2, k + 1):
            edges.append((i - 1, i))
        # Attach remaining nodes to root (id 1)
        for j in range(k + 1, n + 1):
            edges.append((1, j))
        # Output
        out_lines.append("1")
        for u, v in edges:
            out_lines.append(f"{u} {v}")
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
