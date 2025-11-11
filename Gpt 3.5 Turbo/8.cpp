#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makeBalanced(string s) {
    int n = s.size();
    vector<int> operations;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            char new_char;
            if (s[i] != 'L' && s[i + 1] != 'L') {
                new_char = 'L';
            } else if (s[i] != 'I' && s[i + 1] != 'I') {
                new_char = 'I';
            } else {
                new_char = 'T';
            }

            s.insert(i + 1, 1, new_char);
            operations.push_back(i + 1);
            i++; // Skip the inserted character
            if (operations.size() >= 2 * n) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << operations.size() << endl;
    for (int op : operations) {
        cout << op << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        makeBalanced(s);
    }

    return 0;
}
