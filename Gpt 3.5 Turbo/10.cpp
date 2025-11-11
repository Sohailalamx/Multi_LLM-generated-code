#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 2e5 + 5;
int n, k;
vector<int> zerosCount;
vector<vector<int>> children;
unordered_map<int, unordered_map<string, int>> dp;

int getBeauty(int node, int zeros) {
    if (dp[node].find(to_string(zeros)) != dp[node].end()) {
        return dp[node][to_string(zeros)];
    }

    if (children[node].empty()) {
        if (zeros == 0) {
            dp[node][to_string(zeros)] = 1;
        } else {
            dp[node][to_string(zeros)] = 0;
        }
        return dp[node][to_string(zeros)];
    }

    dp[node][to_string(zeros)] = 0;
    for (int child : children[node]) {
        for (int i = 0; i <= min(zeros, zerosCount[child]); ++i) {
            dp[node][to_string(zeros)] = max(dp[node][to_string(zeros)], getBeauty(child, i) + getBeauty(node, zeros - i));
        }
    }

    return dp[node][to_string(zeros)];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        zerosCount.resize(n + 1, 0);
        children.resize(n + 1);
        dp.clear();

        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            children[parent].push_back(i);
        }

        for (int i = 1; i <= n; ++i) {
            zerosCount[i] = (i <= k ? 1 : 0);
        }

        int maxBeauty = getBeauty(1, k);
        cout << maxBeauty << endl;
    }

    return 0;
}
