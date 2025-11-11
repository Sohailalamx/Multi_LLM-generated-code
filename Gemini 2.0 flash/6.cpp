#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_decreasing_subsequence(const vector<int>& arr) {
  if (arr.empty()) {
    return 0;
  }

  vector<int> tail;
  for (int x : arr) {
    if (tail.empty() || x < tail.back()) {
      tail.push_back(x);
    } else {
      auto it = upper_bound(tail.begin(), tail.end(), x, greater<int>());
      if (it != tail.end()) {
        *it = x;
      }
    }
  }
  return tail.size();
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }

    long long total_lds_length = 0;
    for (int l = 0; l < n; ++l) {
      for (int r = l; r < n; ++r) {
        vector<int> subarray;
        for (int i = l; i <= r; ++i) {
          subarray.push_back(p[i]);
        }
        total_lds_length += longest_decreasing_subsequence(subarray);
      }
    }

    cout << total_lds_length << endl;
  }

  return 0;
}
