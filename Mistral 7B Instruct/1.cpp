#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    unordered_map<int, int> freq;
    for (int num : b) {
        freq[num]++;
    }

    // Check if the sum of frequencies exceeds n
    int total = 0;
    for (auto& [num, cnt] : freq) {
        total += cnt;
    }
    if (total > n) {
        cout << -1 << endl;
        return;
    }

    // Check if any frequency is 0 (invalid)
    for (auto& [num, cnt] : freq) {
        if (cnt == 0) {
            cout << -1 << endl;
            return;
        }
    }

    // Sort the frequencies in descending order
    vector<pair<int, int>> sorted_freq;
    for (auto& [num, cnt] : freq) {
        sorted_freq.emplace_back(cnt, num);
    }
    sort(sorted_freq.begin(), sorted_freq.end(), greater<pair<int, int>>());

    vector<int> a(n);
    int current = 1;
    for (auto& [cnt, num] : sorted_freq) {
        for (int i = 0; i < cnt; ++i) {
            a[i] = num;
        }
    }

    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
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