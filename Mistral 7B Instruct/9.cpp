#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n, m, V;
    cin >> n >> m >> V;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check if the graph is a tree
    vector<bool> visited(n, false);
    int root = 0;
    visited[root] = true;
    int edges = 0;
    for (int u : adj[root]) {
        if (!visited[u]) {
            edges++;
            visited[u] = true;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            for (int u : adj[i]) {
                if (visited[u]) {
                    edges++;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    if (edges != n - 1) {
        cout << 0 << endl;
        return;
    }

    // The graph is a tree, proceed to find the number of valid assignments
    vector<int> parent(n, -1);
    vector<int> depth(n, 0);
    vector<int> xor_path(n, 0);
    vector<bool> has_value(n, false);

    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            has_value[i] = true;
        }
    }

    // BFS to find the root and compute the XOR path
    vector<bool> visited_tree(n, false);
    vector<int> queue;
    queue.push_back(0);
    visited_tree[0] = true;
    while (!queue.empty()) {
        int u = queue.back();
        queue.pop_back();
        for (int v : adj[u]) {
            if (!visited_tree[v]) {
                visited_tree[v] = true;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                if (has_value[u] && has_value[v]) {
                    xor_path[v] = xor_path[u] ^ a[u] ^ a[v];
                } else if (has_value[u]) {
                    xor_path[v] = xor_path[u] ^ a[u];
                } else if (has_value[v]) {
                    xor_path[v] = a[v];
                }
                queue.push_back(v);
            }
        }
    }

    // Check if the XOR path is consistent
    bool consistent = true;
    for (int i = 0; i < n; ++i) {
        if (has_value[i]) {
            int current_xor = 0;
            int u = i;
            while (u != -1) {
                if (has_value[u]) {
                    current_xor ^= a[u];
                }
                u = parent[u];
            }
            if (current_xor != xor_path[i]) {
                consistent = false;
                break;
            }
        }
    }

    if (!consistent) {
        cout << 0 << endl;
        return;
    }

    // Count the number of ways to assign the missing weights
    int missing = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            missing++;
        }
    }

    if (missing == 0) {
        cout << 1 << endl;
        return;
    }

    // The number of valid assignments is V^(missing - 1)
    long long result = 1;
    for (int i = 0; i < missing - 1; ++i) {
        result = (result * V) % MOD;
    }
    cout << result << endl;
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