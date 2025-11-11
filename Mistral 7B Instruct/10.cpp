#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> parent(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
    }

    // Build the tree structure
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        children[parent[i]].push_back(i);
    }

    // DP[i][j][l] represents the maximum LCS length when we have i zeros and j ones, and the current LCS length is l
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n - k + 1, 0)));

    // Initialize DP for the root
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= n - k; ++l) {
                if (dp[i][j][l] == 0) continue;

                // Assign 0 to the current node
                if (j < k) {
                    for (int child : children[i]) {
                        dp[child][j + 1][l + (l > 0 ? 1 : 0)] = (dp[child][j + 1][l + (l > 0 ? 1 : 0)] + dp[i][j][l]) % MOD;
                    }
                }

                // Assign 1 to the current node
                if (l < n - k) {
                    for (int child : children[i]) {
                        dp[child][j][l + 1] = (dp[child][j][l + 1] + dp[i][j][l]) % MOD;
                    }
                }
            }
        }
    }

    // The answer is the maximum LCS length among all leaves
    int max_lcs = 0;
    for (int j = 0; j <= k; ++j) {
        for (int l = 0; l <= n - k; ++l) {
            if (dp[n][j][l] > 0) {
                max_lcs = max(max_lcs, l);
            }
        }
    }

    cout << max_lcs << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}