"""
This module solves the 'Divine Tree' problem by constructing a tree with
n nodes such that the sum of divineness of all nodes equals m.
"""

import sys

# Increase recursion depth just in case
sys.setrecursionlimit(2000)


def calculate_spine_sum(mid, n):
    """
    Calculates the total divineness sum for a spine of height 'mid'.
    Configuration: Spine 1..mid, with all remaining (n-mid) nodes attached to mid.
    """
    return (mid * (mid + 1)) // 2 + (n - mid) * mid


def find_spine_height(n, m):
    """
    Binary searches for the smallest spine height k such that the base
    configuration yields a sum >= m.
    Returns the optimal height k.
    """
    low = 1
    high = n
    k = 1

    while low <= high:
        mid = (low + high) // 2
        s_mid = calculate_spine_sum(mid, n)

        if s_mid >= m:
            k = mid
            high = mid - 1
        else:
            low = mid + 1
    return k


def process_test_case(n, m):
    """
    Processes a single test case. Returns a list of strings representing the
    output for this case, or ["-1"] if no solution exists.
    """
    # Minimum possible total divineness is n (Root at 1, all nodes get value 1)
    min_sum = n
    # Maximum possible total divineness is n*(n+1)/2 (Root at n)
    max_sum = n * (n + 1) // 2

    if m < min_sum or m > max_sum:
        return ["-1"]

    k = find_spine_height(n, m)

    # Calculate how much we exceeded m using this k
    current_sum = calculate_spine_sum(k, n)
    excess = current_sum - m

    case_output = []
    # 1. The Root
    case_output.append(str(k))

    # 2. The Spine (Edges from k down to 1)
    for i in range(k, 1, -1):
        case_output.append(f"{i} {i-1}")

    # 3. The Free Nodes (k+1 to n)
    for u in range(k + 1, n + 1):
        if excess > 0:
            max_reduction = k - 1
            if excess >= max_reduction:
                # Move to parent 1 for max reduction
                case_output.append(f"{u} 1")
                excess -= max_reduction
            else:
                # Attach to parent p to get exact reduction needed
                p = k - excess
                case_output.append(f"{u} {p}")
                excess = 0
        else:
            # No more reduction needed, attach to k
            case_output.append(f"{u} {k}")

    return case_output


def solve():
    """
    Main function to read input and print solutions for all test cases.
    """
    try:
        input_data = sys.stdin.read().split()
    except (IOError, ValueError):
        return

    if not input_data:
        return

    iterator = iter(input_data)

    try:
        t_str = next(iterator, None)
        if not t_str:
            return
        num_test_cases = int(t_str)
    except StopIteration:
        return

    all_output = []

    for _ in range(num_test_cases):
        try:
            n_val = int(next(iterator))
            m_val = int(next(iterator))
            all_output.extend(process_test_case(n_val, m_val))
        except StopIteration:
            break

    sys.stdout.write('\n'.join(all_output) + '\n')


if __name__ == '__main__':
    solve()