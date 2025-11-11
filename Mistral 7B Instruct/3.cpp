#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

vector<int> prime_factors(int x) {
    vector<int> factors;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            factors.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        factors.push_back(x);
    }
    return factors;
}

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Check if there's already a pair with gcd > 1
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (gcd(a[i], a[j]) > 1) {
                return 0;
            }
        }
    }

    unordered_map<int, vector<int>> prime_to_indices;
    for (int i = 0; i < n; ++i) {
        vector<int> factors = prime_factors(a[i]);
        for (int p : factors) {
            prime_to_indices[p].push_back(i);
        }
    }

    int min_cost = INT_MAX;
    for (auto& [p, indices] : prime_to_indices) {
        if (indices.size() >= 2) {
            // The cost is the sum of b[i] for all i not in indices, except the smallest b[i] in indices
            vector<int> costs;
            for (int i = 0; i < n; ++i) {
                bool found = false;
                for (int idx : indices) {
                    if (i == idx) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    costs.push_back(b[i]);
                }
            }
            sort(costs.begin(), costs.end());
            int total = 0;
            for (int i = 0; i < costs.size(); ++i) {
                if (i == 0) {
                    continue; // skip the smallest cost
                }
                total += costs[i];
            }
            for (int idx : indices) {
                total += b[idx];
            }
            min_cost = min(min_cost, total);
        }
    }

    if (min_cost == INT_MAX) {
        // All elements are co-prime, need to make at least two elements share a prime
        // The minimal cost is to make two elements equal to 1 (since 1 is co-prime with everything)
        // But since b[i] = 1, the cost is to make two elements 1, which is 0 if they are already 1
        // Otherwise, the minimal cost is to make two elements 1, which is 2 (since each needs to be increased to 1)
        // But since b[i] = 1, the cost is 2.
        // However, if there are already two 1's, the cost is 0.
        int count_ones = 0;
        for (int num : a) {
            if (num == 1) {
                count_ones++;
            }
        }
        if (count_ones >= 2) {
            return 0;
        } else {
            return 2;
        }
    } else {
        return min_cost;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}