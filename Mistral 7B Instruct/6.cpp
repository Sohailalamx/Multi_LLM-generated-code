#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> peaks;
    for (int i = 1; i < n - 1; ++i) {
        if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
            peaks.push_back(i);
        }
    }

    long long total = 0;
    int prev = 0;
    for (int peak : peaks) {
        int length = peak - prev + 1;
        total += (long long)length * (length + 1) / 2;
        prev = peak;
    }

    int last = peaks.empty() ? 0 : peaks.back();
    int length = n - last;
    if (length > 0) {
        total += (long long)length * (length + 1) / 2;
    }

    cout << total << endl;
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