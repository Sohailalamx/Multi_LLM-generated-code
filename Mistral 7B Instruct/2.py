def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
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
        # Convert the lists to sets for easier intersection
        set_a = set(a)
        set_b = set(b)
        # Find the intersection of the two sets
        common = set_a & set_b
        # The maximum number of suggestions is the sum of the lengths of the two lists
        # minus the length of the intersection
        max_suggestions = n + m - len(common)
        print(max_suggestions)

solve()