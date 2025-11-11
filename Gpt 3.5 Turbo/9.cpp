#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
vector<int> a;
int dp[MAXN][2];

int add(int a, int b) {
    return (a + b) % MOD;
}

void dfs(int v, int p) {
    dp[v][0] = dp[v][1] = 1;

    for (int u : adj[v]) {
        if (u == p) continue;

        dfs(u, v);

        if (a[v] != -1) {
            dp[v][1] = (1LL * dp[v][1] * dp[u][a[v]]) % MOD;
            dp[v][0] = (1LL * dp[v][0] * add(dp[u][0], dp[u][1])) % MOD;
        } else {
            dp[v][1] = (1LL * dp[v][1] * add(dp[u][0], dp[u][1])) % MOD;
            dp[v][0] = (1LL * dp[v][0] * dp[u][1]) % MOD;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, V;
        cin >> n >> m >> V;

        a.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);
        int ans = a[1] == -1 ? add(dp[1][0], dp[1][1]) : dp[1][a[1]];
        cout << ans << endl;
    }

    return 0;
}
