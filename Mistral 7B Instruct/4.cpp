#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m < n) {
        cout << -1 << endl;
        return;
    }

    if (m == n) {
        cout << 1 << endl;
        for (int i = 2; i <= n; ++i) {
            cout << 1 << " " << i << endl;
        }
        return;
    }

    // Calculate the number of nodes that need to have divineness 1
    int k = (m - n) / (n - 1);
    if (k <= 0) {
        cout << -1 << endl;
        return;
    }

    // The root is k + 1
    cout << k + 1 << endl;

    // Connect 1 to k + 1
    cout << 1 << " " << k + 1 << endl;

    // Connect 2 to k + 1
    cout << 2 << " " << k + 1 << endl;

    // Connect the rest of the nodes to 1
    for (int i = 3; i <= n; ++i) {
        cout << 1 << " " << i << endl;
    }
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