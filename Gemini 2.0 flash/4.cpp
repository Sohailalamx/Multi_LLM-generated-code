#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        if (m < n || m > n * (n + 1) / 2 - (n - 1)) {
            cout << -1 << endl;
            continue;
        }

        if (n == 1 && m != 1) {
            cout << -1 << endl;
            continue;
        }

        long long root = 1;
        if(n > 1){
        
        long long sum_if_root_is_one = n * 1LL;
        if (m == sum_if_root_is_one) {
            cout << 1 << endl;
            for (int i = 1; i < n; ++i) {
                cout << 1 << " " << i + 1 << endl;
            }
            continue;
        }

         long long sum_if_root_is_n =1*n+(n -1) *1LL;
        if (m == sum_if_root_is_n) 
         { 
             cout << n << endl;
        long long parent = n; 
          
           for(int i = 1; i < n ; i++) if(i != n) { 
             cout << parent << " " << i << endl ; 
           } 
            continue;
         }
            
         
         root = 2;
        long long sum_if_root_is_two = 2LL*1 + (n-1) *1;
         if(m == sum_if_root_is_two && n >=2){
               cout << 2 << endl;
               for(int i = 1; i <= n; ++i){
                 if(i != 2)
                  cout << 2 << " " << i << endl;
               }
               continue;
            }

            
           
                cout << n << endl;
                for (int i = 1; i < n; ++i) {
                    cout << n << " " << i << endl;
                   
                }
            
            continue;
           } 
    
     }

    return 0;
}
