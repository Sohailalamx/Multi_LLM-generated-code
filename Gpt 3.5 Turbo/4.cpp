#include <iostream>
#include <vector>

using namespace std;

void solveDivineTree(int n, long long m) {
    if (m < 1 || m > n - 1 + (n * (n - 1)) / 2) {
        cout << -1 << endl; // No solution possible
        return;
    }

    if (n == 1 && m == 1) {
        cout << 1 << endl; // Root is 1 if n=1 and m=1
        return;
    }

    long long sum = 0;
    int root = 0;

    for (int i = 1; i <= n; ++i) {
        if (sum + i >= m) {
            root = i;
            break;
        }
        sum += i;
    }

    cout << root << endl;

    for (int i = 1; i < root; ++i) {
        cout << root << " " << i << endl;
    }

    for (int i = root + 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (sum == m) return;
            cout << i << " " << j << endl;
            sum++;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long m;
        cin >> n >> m;

        solveDivineTree(n, m);
    }

    return 0;
}
