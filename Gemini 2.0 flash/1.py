
def solve():
    n = int(input())
    b = list(map(int, input().split()))

    if sum(b) != n:
        print(-1)
        return
    
    counts = {}
    for x in b:
        counts[x] = counts.get(x, 0) + 1

    sorted_counts = sorted(counts.items())

    if any(count > freq for freq, count in zip(b, b[1:])):
        print(-1)
        return

    a = [0] * n
    num_used = 1
    for i in range(n):
        a[i] = num_used
        num_used += 1
    
    print(*a)

t = int(input())
for _ in range(t):
    solve()
