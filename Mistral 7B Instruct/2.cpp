#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        unordered_set<int> setA(a.begin(), a.end());
        unordered_set<int> setB(b.begin(), b.end());

        unordered_set<int> intersection;
        for (int num : a) {
            if (setB.count(num)) {
                intersection.insert(num);
            }
        }

        int total = n + m - intersection.size();
        cout << total << '\n';
    }

    return 0;
}