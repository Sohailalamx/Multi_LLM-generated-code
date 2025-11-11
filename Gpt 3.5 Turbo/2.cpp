#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int maxSuggestions(int n, int m, vector<int>& a, vector<int>& b) {
    int maxSuggestions = 1;
    unordered_set<int> common(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        if (common.count(a[i])) {
            maxSuggestions += i;
            break;
        }
    }

    return maxSuggestions;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        cout << maxSuggestions(n, m, a, b) << endl;
    }

    return 0;
}
