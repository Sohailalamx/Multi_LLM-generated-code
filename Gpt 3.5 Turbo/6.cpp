#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> perm(n);
        for (int i = 0; i < n; i++) {
            cin >> perm[i];
        }

        vector<int> l(n), r(n);
        vector<long long> dp(n);

        l[0] = 1;
        for (int i = 1; i < n; i++) {
            l[i] = 1;
            if (perm[i] < perm[i - 1]) {
                l[i] = l[i - 1] + 1;
            }
        }

        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            r[i] = 1;
            if (perm[i] > perm[i + 1]) {
                r[i] = r[i + 1] + 1;
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1 + l[i] + r[i];
            sum += dp[i];
        }

        cout << sum << "\n";
    }

    return 0;
}
