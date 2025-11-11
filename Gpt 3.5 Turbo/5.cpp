#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void minimizePalindromicSubarrays(int n, int k, vector<int>& a) {
    vector<int> added;
    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - i - 1]) {
            pq.push({min(a[i], a[n - i - 1]), k - 1});
        }
    }

    while (k > 0 && !pq.empty()) {
        auto [val, count] = pq.top();
        pq.pop();
        added.push_back(val);
        k--;

        if (count > 1) {
            pq.push({val, count - 1});
        }
    }

    cout << added.size() << endl;
    for (int val : added) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        minimizePalindromicSubarrays(n, k, a);
    }

    return 0;
}
