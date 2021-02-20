//https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s1="",s2="";
        for(int i=0;i<S.length();i++){
            if(S[i]!='#') s1.push_back(S[i]);
            else if(s1.length()>0) s1.pop_back();
        }
        for(int i=0;i<T.length();i++){
            if(T[i]!='#') s2.push_back(T[i]);
            else if(s2.length()>0) s2.pop_back();
        }
        return s1==s2?true:false;
    }
