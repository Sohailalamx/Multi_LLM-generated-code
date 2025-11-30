import sys
from collections import defaultdict, Counter

def solve() -> None:
    data = list(map(int, sys.stdin.read().split()))
    t = data[0]
    idx = 1
    out_lines = []
    for _ in range(t):
        n = data[idx]; idx += 1
        b = data[idx:idx+n]; idx += n

        freq = Counter(b)
        possible = all(cnt % val == 0 for val, cnt in freq.items())
        if not possible:
            out_lines.append("-1")
            continue

        # map each value to the list of indices having that value in b
        pos_map = defaultdict(list)
        for i, val in enumerate(b):
            pos_map[val].append(i)

        a = [0] * n
        cur_val = 1
        for val, pos_list in pos_map.items():
            for i in range(0, len(pos_list), val):
                group = pos_list[i:i+val]
                for p in group:
                    a[p] = cur_val
                cur_val += 1

        out_lines.append(' '.join(map(str, a)))
    sys.stdout.write('\n'.join(out_lines))

if __name__ == "__main__":
    solve()
