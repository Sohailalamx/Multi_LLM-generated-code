#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<int> elements(a.begin(), a.end());
    vector<int> result;

    // First, append all elements not in the array
    for (int x = 1; x <= n; ++x) {
        if (elements.find(x) == elements.end()) {
            result.push_back(x);
            elements.insert(x);
            if (result.size() == k) {
                break;
            }
        }
    }

    // If we still need to append more elements, append the first element
    while (result.size() < k) {
        result.push_back(a[0]);
    }

    for (int x : result) {
        cout << x << " ";
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