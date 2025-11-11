#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long minCost(int n, vector<int>& a, vector<int>& b) {
    map<int, long long> freq;

    for (int i = 0; i < n; ++i) {
        freq[a[i]] += b[i];
    }

    long long minCost = LLONG_MAX;

    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int ai = it->first;
        long long totalCost = 0;

        for (int i = 2; i * i <= ai; ++i) {
            if (ai % i == 0) {
                int gcdVal = gcd(i, ai);
                totalCost += 1LL * gcdVal * it->second;
                break;
            }
        }

        minCost = min(minCost, totalCost);
    }

    return minCost;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        cout << minCost(n, a, b) << endl;
    }

    return 0;
}
