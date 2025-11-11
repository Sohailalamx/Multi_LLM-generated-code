#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> a(n);
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {b[i], i};
    }
    sort(pairs.begin(), pairs.end());

    vector<int> counts(n + 1, 0);
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        a[pairs[i].second] = i + 1;
        counts[b[pairs[i].second]]++;
    }

    vector<int> check_counts(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        check_counts[a[i]]++;
    }

    vector<int> freqs(n + 1, 0);
    for(int i = 0; i < n; ++i){
        freqs[a[i]]++;
    }

    vector<int> b_check(n);
    for(int i = 0; i < n; ++i){
        int count = 0;
        for(int j = 0; j < n; ++j){
            if(a[j] == i + 1){
                count++;
            }
        }
        b_check[i] = count;
    }

    for(int i = 0; i < n; ++i){
        int count = 0;
        for(int j = 0; j < n; ++j){
            if(a[j] == j + 1){
                count++;
            }
        }
    }
    
    vector<int> f_a(n + 1, 0);
    for(int i = 0; i < n; ++i){
        f_a[a[i]]++;
    }

    for(int i = 0; i < n; ++i){
        if(f_a[i + 1] != b[i]){
            possible = false;
            break;
        }
    }
    

    if (!possible) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
