"""
This module solves the problem by reading inputs and checking conditions
to print the constructed array or -1.
"""

def solve():
    """
    Reads n and list b, validates the input based on problem constraints,
    and prints the resulting array a.
    """
    try:
        line = input()
        if not line:
            return
        n = int(line)
        b = list(map(int, input().split()))
    except (EOFError, ValueError):
        return

    if sum(b) != n:
        print(-1)
        return

    counts = {}
    for x in b:
        counts[x] = counts.get(x, 0) + 1

    # The unused variable 'sorted_counts' has been removed here.

    if any(count > freq for freq, count in zip(b, b[1:])):
        print(-1)
        return

    a = [0] * n
    num_used = 1
    for i in range(n):
        a[i] = num_used
        num_used += 1

    print(*a)


if __name__ == "__main__":
    try:
        t_str = input()
        if t_str:
            t = int(t_str)
            for _ in range(t):
                solve()
    except (EOFError, ValueError):
        pass