#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int l = freq['L'], i = freq['I'], t = freq['T'];
    int total = l + i + t;
    int target = total / 3;
    if (total % 3 != 0) {
        cout << -1 << endl;
        return;
    }

    int dl = target - l;
    int di = target - i;
    int dt = target - t;

    vector<int> operations;
    int m = 0;

    // We need to insert dl L's, di I's, and dt T's
    // We can insert between adjacent different characters
    for (int pos = 0; pos < n - 1; ++pos) {
        if (s[pos] != s[pos + 1]) {
            if (dl > 0 && s[pos] != 'L' && s[pos + 1] != 'L') {
                operations.push_back(pos + 1);
                dl--;
                m++;
            } else if (di > 0 && s[pos] != 'I' && s[pos + 1] != 'I') {
                operations.push_back(pos + 1);
                di--;
                m++;
            } else if (dt > 0 && s[pos] != 'T' && s[pos + 1] != 'T') {
                operations.push_back(pos + 1);
                dt--;
                m++;
            }
        }
    }

    if (dl == 0 && di == 0 && dt == 0) {
        cout << m << endl;
        for (int op : operations) {
            cout << op << endl;
        }
    } else {
        cout << -1 << endl;
    }
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