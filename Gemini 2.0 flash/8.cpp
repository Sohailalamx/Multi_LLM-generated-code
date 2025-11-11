#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> indices;
        string current_s = s;

        
        for (int k = 0; k < 2 * n; k++) {
            int l_count = 0, i_count = 0, t_count = 0;
            for (char c : current_s) {
                if (c == 'L') l_count++;
                if (c == 'I') i_count++;
                if (c == 'T') t_count++;
            }

            if (l_count == i_count && i_count == t_count) {
                cout << indices.size() << endl;
                for (int index : indices) {
                    cout << index << endl;
                }
                goto next_test_case;
            }

            bool op_performed = false;
            for (int i = 0; i < current_s.length() - 1; ++i) {
                if (current_s[i] != current_s[i + 1]) {
                    char insert_char;
                    if (current_s[i] == 'L' && current_s[i + 1] == 'I') insert_char = 'T';
                    else if (current_s[i] == 'L' && current_s[i + 1] == 'T') insert_char = 'I';
                    else if (current_s[i] == 'I' && current_s[i + 1] == 'L') insert_char = 'T';
                    else if (current_s[i] == 'I' && current_s[i + 1] == 'T') insert_char = 'L';
                    else if (current_s[i] == 'T' && current_s[i + 1] == 'L') insert_char = 'I';
                    else insert_char = 'L';

                    current_s.insert(i + 1, 1, insert_char);
                    indices.push_back(i + 1);
                    op_performed = true;
                    break;
                }
            }
            if(!op_performed) break;
        }

        
        int l_count = 0, i_count = 0, t_count = 0;
        for (char c : current_s) {
            if (c == 'L') l_count++;
            if (c == 'I') i_count++;
            if (c == 'T') t_count++;
        }

        if (l_count == i_count && i_count == t_count) {
            cout << indices.size() << endl;
            for (int index : indices) {
                cout << index << endl;
            }
            goto next_test_case;
        }

        cout << -1 << endl;

        next_test_case:;
    }
    return 0;
}
