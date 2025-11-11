#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int k) {
    if (k > (n * (n - 1)) / 2) {
        cout << "0\n";
        return;
    }

    vector<int> perm(n);
    for (int i = 1; i <= n; ++i) {
        perm[i - 1] = i;
    }

    // Adjust the permutation to have k inversions
    for (int i = n - 2; i >= 0; --i) {
        if (k == 0) break;
        if (k >= n - i) {
            swap(perm[i], perm[i + n - k]);
            k -= (n - i);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << perm[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}
