#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_inversion_value(const vector<int>& p) {
    int n = p.size();
    int count = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            bool has_inversion = false;
            for (int i = l; i <= r; ++i) {
                for (int j = i + 1; j <= r; ++j) {
                    if (p[i] > p[j]) {
                        has_inversion = true;
                        break;
                    }
                }
                if (has_inversion) break;
            }
            if (has_inversion) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i + 1;
        }

        bool found = false;
        vector<int> result;

        vector<int> initial_p = p;
        do {
            if (calculate_inversion_value(p) == k) {
                found = true;
                result = p;
                break;
            }
        } while (next_permutation(p.begin(), p.end()));

        if (found) {
            for (int i = 0; i < n; ++i) {
                cout << result[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
