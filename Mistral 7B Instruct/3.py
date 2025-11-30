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
        if m < n or m > n * (n + 1) // 2:
            print(-1)
            continue
        # The root should be the smallest possible number to minimize the total divineness
        root = 1
        # The total divineness is the sum of the first n natural numbers
        total_divineness = n * (n + 1) // 2
        if m == total_divineness:
            # The tree is a star graph with the root connected to all other nodes
            print(root)
            for i in range(2, n + 1):
                print(f"{root} {i}")
        else:
            # We need to find a way to reduce the total divineness to m
            # We can do this by making some nodes have a higher divineness
            # For example, we can make a subtree with a higher divineness
            # The idea is to find the smallest k such that the sum of the first k natural numbers is less than or equal to m
            # and the sum of the first (k + 1) natural numbers is greater than m
            # Then, the root of the subtree should be k + 1
            # The remaining nodes should be connected to the root
            # The total divineness of the subtree is the sum of the first k natural numbers
            # The total divineness of the remaining nodes is (n - k) * (k + 1)
            # The total divineness of the tree is the sum of the divineness of the subtree and the remaining nodes
            # We need to find k such that the total divineness is equal to m
            # We can use binary search to find the optimal k
            left = 1
            right = n
            answer = -1
            while left <= right:
                mid = (left + right) // 2
                # The total divineness of the subtree is the sum of the first mid natural numbers
                subtree_divineness = mid * (mid + 1) // 2
                # The total divineness of the remaining nodes is (n - mid) * (mid + 1)
                remaining_divineness = (n - mid) * (mid + 1)
                total = subtree_divineness + remaining_divineness
                if total == m:
                    answer = mid + 1
                    break
                elif total < m:
                    left = mid + 1
                else:
                    right = mid - 1
            if answer == -1:
                print(-1)
            else:
                print(answer)
                # The root is answer
                # The first answer nodes form a subtree
                # The remaining nodes are connected to the root
                # The subtree is a star graph with the root connected to all other nodes in the subtree
                for i in range(2, answer + 1):
                    print(f"{answer} {i}")
                for i in range(answer + 1, n + 1):
                    print(f"{answer} {i}")

solve()