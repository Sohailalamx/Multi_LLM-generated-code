def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
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
        # We need to find a permutation of numbers from 1 to n such that
        # the frequency of each number in the permutation matches the frequency in b
        # The key idea is to assign the largest frequency to the smallest available number
        # and so on.
        # We can use a greedy approach to assign the numbers.
        # We need to sort the frequencies in descending order and assign the largest frequency
        # to the smallest available number.
        # We can use a set to keep track of the numbers that have been assigned.
        assigned = set()
        a = []
        # We need to sort the frequencies in descending order
        sorted_freq = sorted(freq.items(), key=lambda x: -x[1])
        # We need to assign the largest frequency to the smallest available number
        for num, count in sorted_freq:
            # We need to find the smallest available number that is not in the assigned set
            # and is greater than or equal to the current number
            # We can use a variable to keep track of the current number to assign
            current_num = 1
            while current_num in assigned or current_num > n:
                current_num += 1
            # We need to assign the current number to the current frequency
            for _ in range(count):
                a.append(current_num)
            assigned.add(current_num)
        # We need to check if the length of a is equal to n
        if len(a) != n:
            print(-1)
        else:
            print(' '.join(map(str, a)))

solve()
