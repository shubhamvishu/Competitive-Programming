//https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>v1(numRows);
        string res="";
        int x=1;
        if(numRows==1)
            return s;
        for(int i=0,j=0;j<s.length();j++)
        {
            if(i==0)
                x=1;
            else if(i==(numRows-1))
                x=-1;
            v1[i].push_back(s[j]);
            if(x==1)
                i++;
            else if(x==-1)
                i--;
        }
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v1[i].size();j++)
            {
                res.append(1,v1[i][j]);
            }
        }
        return res;
    }
};
