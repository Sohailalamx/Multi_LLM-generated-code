#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  long long min_cost = -1;

  for (int i = 0; i < (1 << (2 * n)); ++i) {
    
    vector<int> current_a = a;
    long long current_cost = 0;

    for (int j = 0; j < n; ++j) {
      if ((i >> (2 * j)) & 1) {
        current_a[j]++;
        current_cost += b[j];
      }
      if ((i >> (2 * j + 1)) & 1) {
        current_a[j] += 2 - (a[j] % 2);
        current_cost += b[j];

      
      }
    }

    bool gcd_found = false;
    for (int j = 0; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (gcd(current_a[j], current_a[k]) > 1) {
          gcd_found = true;
          break;
        }
      }
      if (gcd_found) break;
    }

    if (gcd_found) {
      if (min_cost == -1 || current_cost < min_cost) {
        min_cost = current_cost;
      }
    }
  }
    long long ans = -1;

    for(int i = 0; i < (1 << n); ++i){
         
        vector<int> temp_a = a;
        long long cost = 0;

        for(int j = 0; j < n; ++j){
            if((i >> j) & 1){
                temp_a[j]++;
                cost += b[j];
            }
        }

        bool found = false;
        for(int j = 0; j < n; ++j){
            for(int k = j + 1; k < n; ++k){
                if(gcd(temp_a[j], temp_a[k]) > 1){
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        if(found){
            if(ans == -1 || cost < ans){
                ans = cost;
            }
        }
    }

    if(ans == -1){
        vector<int> temp_a = a;
        long long cost = 0;
       for(int i = 0; i < n; i++){
         temp_a[i]++;
         cost+=b[i];
       }
        
        
        
          vector<int> temp_b = a;
          long long cost2 = 0;
          
          for(int i = 0; i < n; ++i){
            if(a[i]%2 != 0){
              cost2+=b[i];
              temp_b[i]++;
            }
            
            
          }
        
        
         
        return min(cost, cost2);
        
    }

      vector<int> temp_a = a;
      long long cost1 = 0;
      for(int i = 0; i < n; i++){
         temp_a[i] = temp_a[i] + 1;
         cost1+=b[i];
       }
        
    return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
