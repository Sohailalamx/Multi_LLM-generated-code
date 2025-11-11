#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        unordered_map<int, int> counts;

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            counts[b[i]]++;
        }

        vector<int> a(n, -1);
        bool valid = true;

        for (int i = 0; i < n; ++i) {
            if (counts[b[i]] < b[i]) {
                valid = false;
                break;
            }

            a[i] = b[i];
            counts[b[i]]--;
        }

        if (valid) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
