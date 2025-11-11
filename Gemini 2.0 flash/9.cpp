#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_balanced(int n, const vector<int>& a, const vector<vector<int>>& adj) {
    for (int p = 0; p < n; ++p) {
        for (int q = p + 1; q < n; ++q) {
            vector<int> path_values;

            function<void(int, int, vector<int>)> dfs = 
                [&](int u, int target, vector<int> current_path) {
                current_path.push_back(u);

                if (u == target) {
                    int path_value = 0;
                    for (int node : current_path) {
                        path_value ^= a[node];
                    }
                    path_values.push_back(path_value);
                    return;
                }

                for (int v : adj[u]) {
                    bool visited = false;
                    for (int node : current_path) {
                        if (node == v) {
                            visited = true;
                            break;
                        }
                    }
                    if (!visited) {
                        dfs(v, target, current_path);
                    }
                }
            };

            dfs(p, q, {});

            if (path_values.empty()) return false; 

            int expected_value = path_values[0];
            for (int path_value : path_values) {
                if (path_value != expected_value) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
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
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long count = 0;

        vector<int> unknown_indices;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                unknown_indices.push_back(i);
            }
        }

        int num_unknown = unknown_indices.size();
        vector<int> assignment(num_unknown);

        function<void(int)> generate_assignments = [&](int k) {
            if (k == num_unknown) {
                
                vector<int> current_a = a;
                for (int i = 0; i < num_unknown; ++i) {
                    current_a[unknown_indices[i]] = assignment[i];
                }

                if (is_balanced(n, current_a, adj)) {
                    count = (count + 1) % 998244353;
                }
                return;
            }

            for (int i = 0; i < V; ++i) {
                assignment[k] = i;
                generate_assignments(k + 1);
            }
        };

        generate_assignments(0);

        cout << count << endl;
    }
    return 0;
}
