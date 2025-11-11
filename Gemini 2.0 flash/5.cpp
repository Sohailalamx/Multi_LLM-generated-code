#include <iostream>
#include <vector>

using namespace std;

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

        for (int i = 0; i < k; ++i) {
            cout << (i % n) + 1 << (i == k - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
