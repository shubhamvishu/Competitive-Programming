//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string>res;
    void gene(string s,int n,int i)    
    {
        if(s.length()>(2*n))
            return;
        if(s.length()==2*n && i==0)
        { res.push_back(s);
          return;
        }
        if((i+1)<=n)
            gene(s+"(",n,i+1);
        if((i-1)>=0)
            gene(s+")",n,i-1);
    }
    vector<string> generateParenthesis(int n) {
        gene("",n,0);
        return res;
    }
};