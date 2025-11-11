#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<bool> suggested_a(n, false);
    vector<bool> suggested_b(m, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                suggested_a[i] = true;
                suggested_b[j] = true;
                break;
            }
        }
    }

    int max_suggestions = 0;
    for (int i = 0; i < (1 << (n + m)); ++i) {
        
        vector<int> alice_suggestions;
        vector<int> bob_suggestions;

        int current_suggestions = 0;
        
        vector<bool> local_suggested_a(n, false);
        vector<bool> local_suggested_b(m, false);

        
        bool found_common = false;

        
        int alice_index = 0;
        int bob_index = 0;
        
        
        for (int k = 0; k < n + m; ++k) {
            if (k % 2 == 0) { 
                
                int current_move = -1;
                
                for(int j = 0; j < n; j++){
                   bool already_suggested = false;
                    for(int s : alice_suggestions){
                        if(a[j] == s) already_suggested = true;
                    }
                    
                   if(!already_suggested){
                        current_move = a[j];
                        break;
                   }
                }
                if(current_move == -1) break;
                
                 alice_suggestions.push_back(current_move);
                 current_suggestions++;

                
                bool bob_likes = false;
                for (int j = 0; j < m; ++j) {
                    if (current_move == b[j]) {
                        bob_likes = true;
                        break;
                    }
                }
                if (bob_likes) {
                    found_common = true;
                    break;
                }

            } else {
                
                int current_move = -1;
                for(int j = 0; j < m; j++){
                  bool already_suggested = false;
                    for(int s : bob_suggestions){
                        if(b[j] == s) already_suggested = true;
                    }
                   if(!already_suggested){
                        current_move = b[j];
                        break;
                   }
                }
               if(current_move == -1) break;
                
                bob_suggestions.push_back(current_move);
                current_suggestions++;

                bool alice_likes = false;
                 for (int j = 0; j < n; ++j) {
                     if (current_move == a[j]) {
                         alice_likes = true;
                         break;
                     }
                 }
                if (alice_likes) {
                   found_common = true;
                   break;
                }
            }
        }

        if (found_common){
            max_suggestions = max(max_suggestions, current_suggestions);
        }
       
        
    }


    
    int min_suggestions = 100000;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i] == b[j]){
                min_suggestions = 1;
            }
        }
    }

    
    vector<int> common_elements;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(a[i] == b[j]) common_elements.push_back(a[i]);
      }
    }

    if(common_elements.size() > 0){
        

      vector<int> alice_choices = a;
      vector<int> bob_choices = b;

      int ans = 0;

      vector<int> alice_suggested;
      vector<int> bob_suggested;
      
      
        while(true){
            bool found_solution = false;
                    

            int to_suggest_a = -1;
                            
            for(int i = 0; i < alice_choices.size(); ++i){
                bool suggested = false;

                for(int j = 0; j < alice_suggested.size(); ++j){
                    if(alice_choices[i] == alice_suggested[j]) suggested = true;
                }

                if(!suggested){
                    ans++;
                    to_suggest_a = alice_choices[i];
                    alice_suggested.push_back(to_suggest_a);
                   
                    bool bob_likes = false;
                    for(int j = 0; j < bob_choices.size(); ++j){
                        if(to_suggest_a == bob_choices[j]){
                            bob_likes = true;
                            break;
                        }
                    }

                    if(bob_likes){
                      
                        found_solution = true;
                        break;
                    }else{
                      
                    }
                    break;
                }
                
            }
            if(found_solution) break;
                            
                        
            
       
             int to_suggest_b = -1;
             for(int i = 0; i < bob_choices.size(); ++i){

                bool suggested = false;
                 for(int j = 0; j < bob_suggested.size(); ++j){
                    if(bob_choices[i] == bob_suggested[j]) suggested = true;
                 }

                 if(!suggested){
                    ans++;
                   to_suggest_b = bob_choices[i];
                   bob_suggested.push_back(to_suggest_b);
                  

                    bool alice_likes = false;
                   for(int j = 0; j < alice_choices.size(); ++j){
                        if(to_suggest_b == alice_choices[j]){
                            alice_likes = true;
                           break;
                       }
                  }
                    if(alice_likes){
                       found_solution = true;
                        break;
                    }else{
                        
                    }
                    break;
               }
             }
              if(found_solution) break;
                            
            
            if(to_suggest_a == -1 && to_suggest_b == -1){
                break;
            }

             if(to_suggest_a == -1 || to_suggest_b == -1) break;       
        }
       

        return ans;
    }

    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
