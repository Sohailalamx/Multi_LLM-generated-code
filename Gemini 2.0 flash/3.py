import sys

# Increase recursion depth just in case, though iterative approach is used
sys.setrecursionlimit(2000)

def solve():
    # Use fast I/O
    input_data = sys.stdin.read().split()
    
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
        
    output = []
    
    for _ in range(num_test_cases):
        try:
            n = int(next(iterator))
            m = int(next(iterator))
        except StopIteration:
            break
            
        # Minimum possible total divineness is n (Root at 1, all nodes get value 1)
        min_sum = n
        # Maximum possible total divineness is n*(n+1)/2 (Root at n, all nodes get value i)
        max_sum = n * (n + 1) // 2

        if m < min_sum or m > max_sum:
            output.append("-1")
            continue
            
        # Binary search for the smallest k such that the base configuration for k
        # yields a sum >= m.
        # Base configuration for k: Spine k->(k-1)->...->1. All other nodes (k+1..n) attached to k.
        # Sum = (Sum of 1 to k) + (n-k)*k
        
        low = 1
        high = n
        k = 1
        
        while low <= high:
            mid = (low + high) // 2
            # Calculate sum for spine of height mid
            s_mid = (mid * (mid + 1)) // 2 + (n - mid) * mid
            
            if s_mid >= m:
                k = mid
                high = mid - 1
            else:
                low = mid + 1
        
        # Calculate how much we exceeded m using this k
        current_sum = (k * (k + 1)) // 2 + (n - k) * k
        excess = current_sum - m
        
        # Start constructing the output
        # 1. The Root
        output.append(str(k))
        
        # 2. The Spine (Edges from k down to 1)
        for i in range(k, 1, -1):
            output.append(f"{i} {i-1}")
            
        # 3. The Free Nodes (k+1 to n)
        # We distribute the 'excess' reduction among these nodes
        for u in range(k + 1, n + 1):
            if excess > 0:
                # Max reduction we can get from one node is moving it from parent k to parent 1
                # Reduction = k - 1
                max_reduction = k - 1
                
                if excess >= max_reduction:
                    # Move to parent 1 for max reduction
                    output.append(f"{u} 1")
                    excess -= max_reduction
                else:
                    # We need a specific reduction amount R = excess.
                    # We want new value to be k - R.
                    # So we attach to parent p = k - excess.
                    p = k - excess
                    output.append(f"{u} {p}")
                    excess = 0
            else:
                # No more reduction needed, attach to k to keep value maximal
                output.append(f"{u} {k}")
                
    sys.stdout.write('\n'.join(output) + '\n')

if __name__ == '__main__':
    solve()