#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int longest_common_subsequence(const vector<string>& strings) {
    if (strings.empty()) {
        return 0;
    }
    if (strings.size() == 1) return strings[0].length();

    string s1 = strings[0];
    int n = s1.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool is_subsequence = true;
            for(int k = 1; k < strings.size(); ++k){
                string s = strings[k];
                
                int s_idx = 0;
                int target_length = j;
                
                for(int s_i = 0; s_i < s.length(); ++s_i){
                    if(s[s_i] == s1[i-j + target_length -1 ]){
                        s_idx++;
                        if(s_idx == target_length) break;
                    }
                }
                
                if(s_idx != target_length){
                    is_subsequence = false;
                    break;
                }
            }
            if(is_subsequence){
              dp[i][j] = j; 
            } else dp[i][j] = 0;
                   
        }
    }

    int max_len = 0;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            max_len = max(max_len,dp[i][j]);
        }
    }
    
    if(max_len > 0){
        
        return 1;
    }
    
    vector<vector<int>> lcs(s1.length() + 1, vector<int>(strings[1].length() + 1, 0));
       
    for (int i = 1; i <= s1.length(); ++i) {
        for (int j = 1; j <= strings[1].length(); ++j) {
            if (s1[i - 1] == strings[1][j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    return lcs[s1.length()][strings[1].length()];

}

int solve() {
    int n, k;
    cin >> n >> k;

    vector<int> parents(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> parents[i];
        parents[i]--; 
    }

    int max_beauty = 0;
    vector<int> labels(n);
    
    function<void(int,int)> solveLabels = [&](int zerosLeft, int currentIdx){
        
        if(currentIdx == n){
            if(zerosLeft != 0) return;
            vector<vector<int>> adj(n);
            for(int i = 0; i < n - 1; ++i){
                adj[parents[i]].push_back(1 + i);
            }

            vector<string> leaf_names;
              
            function<void(int, string)> build_names = [&](int node, string name){
                name += to_string(labels[node]);
                
                bool is_leaf = adj[node].empty();
              
                if(is_leaf){
                    leaf_names.push_back(name);             
                } else {
                    for(int child : adj[node]){
                        build_names(child, name);
                    }
                }      
            }; 
            
            build_names(0,"");
            max_beauty = max(max_beauty, longest_common_subsequence(leaf_names));
            
            return ;
        }
                
        labels[currentIdx] = 0;
        if(zerosLeft > 0)
            solveLabels(zerosLeft - 1, currentIdx + 1);
          
        labels[currentIdx] = 1;
        solveLabels(zerosLeft, currentIdx + 1);      
    };
    solveLabels(k, 0);
    return max_beauty;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
