//https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
    int k=0;
    if(!s.length()) return true;
     for(char ch:t){
         if(s[k]==ch){
             k++;
             if(k==s.length()) return true;
         }
     }
    return false;
    }
};
