//https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string temp = "";
        vector<string>v;

        for(char ch: s){
            if(ch!=' '){
                temp+=ch;
            }
            else {
                if(temp.length())
                    v.push_back(temp);
                temp = "";
            }
        }
        string result = "";
        if(v.size() && v[v.size()-1].length()) result+=v[v.size()-1];
        for(int i = v.size()-2; i >=0; i--)
            result+=" "+v[i];
        return result;
    }
};
