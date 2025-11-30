"""
This module solves the 'B. Games' problem by calculating the maximum number
of game suggestions Alice and Bob can make based on their exclusive game lists.
"""

import sys

# Increase recursion depth just in case, though iterative approach is used.
sys.setrecursionlimit(2000)


def solve():
    """
    Reads the input, calculates the exclusive games for Alice and Bob,
    and computes the maximum number of suggestions possible.
    """
    # Use fast I/O for efficient execution with large inputs
    try:
        input_data = sys.stdin.read().split()
    except (IOError, ValueError):
        return

    if not input_data:
        return

    iterator = iter(input_data)

    try:
        # Read the number of test cases
        t_str = next(iterator, None)
        if not t_str:
            return
        t = int(t_str)
    except StopIteration:
        return

    output = []

    for _ in range(t):
        try:
            # Read n and m
            n = int(next(iterator))
            m = int(next(iterator))

            # Read Alice's list (a)
            a_list = []
            for _ in range(n):
                a_list.append(int(next(iterator)))

            # Read Bob's list (b)
            b_list = []
            for _ in range(m):
                b_list.append(int(next(iterator)))

            # Convert to sets for O(1) lookups and intersection
            set_a = set(a_list)
            set_b = set(b_list)

            # Identify games present in both lists
            common_count = len(set_a.intersection(set_b))

            # Calculate "exclusive" games (games only one person likes)
            # These are the moves players will prioritize to prolong the game.
            k_a = n - common_count  # Alice's exclusives
            k_b = m - common_count  # Bob's exclusives

            # Logic Analysis:
            # 1. Alice moves first. She wants to pick an exclusive game
            #    to avoid ending the game.
            # 2. Bob moves second. He also wants to pick an exclusive game.
            # 3. They will trade exclusive moves until one runs out.
            # 4. If a player runs out of exclusives, they are forced to pick
            #    a common game, which immediately ends the game
            #    (since the other player likes it too).

            if k_a > k_b:
                # Alice has more exclusives.
                # They play 2 * k_b exclusive moves (exhausting Bob).
                # Alice plays 1 more exclusive move.
                # Bob is then forced to play a common game.
                ans = 2 * k_b + 2
            else:
                # Bob has equal or more exclusives.
                # They play 2 * k_a exclusive moves (exhausting Alice).
                # Alice is then forced to play a common game immediately.
                ans = 2 * k_a + 1

            output.append(str(ans))

        except StopIteration:
            break

    # Print all results efficiently
    sys.stdout.write('\n'.join(output) + '\n')


if __name__ == '__main__':
    solve()