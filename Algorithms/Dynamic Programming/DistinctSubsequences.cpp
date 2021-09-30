//https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(t.length()+1,vector<unsigned long long>(s.length()+1,0));
        for(int i = 0; i <= s.length(); i++) dp[0][i] = 1;
        for(int i = 1; i <= t.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                dp[i][j] += dp[i][j-1];
                if(t[i-1]==s[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[t.length()][s.length()];
    }
};
