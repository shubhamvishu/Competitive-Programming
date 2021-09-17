//https://leetcode.com/problems/reverse-only-letters/


class Solution {
public:
    int next(int index, string s, int factor){
        while(index < s.length() && !((int)s[index]>=65 && (int)s[index]<=90) && !((int)s[index]>=97 && (int)s[index]<=122))   index+=factor;
        return index;
    }
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length()-1;
        i = next(i,s,1);
        j = next(j,s,-1);
        while(i<j){
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            i = next(i+1,s,1);
            j = next(j-1,s,-1);
        }
        return s;
    }
};
