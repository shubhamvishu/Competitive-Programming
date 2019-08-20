//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations (string digits) {
        if(digits=="")
            return vector<string>{};
         map<int,string>m1={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        int x=1,t,total;        
        for(int i=0;i<digits.length();i++)
            x*=m1[digits[i]-'0'].length();
        t=x;
        total=x;
        vector<string>res(x,"");
         for(int i=0;i<digits.length();i++)
         {
             x/=m1[digits[i]-'0'].length();
             for(int j=0;j<m1[digits[i]-'0'].length();j++)
             {
                 
                 for(int k=(j*x);k<total;k+=t)
                 {
                     for(int l=0;l<x;l++)
                     {
                         res[k+l].append(1,m1[digits[i]-'0'][j]);
                     }
                 }
             }
             t/=m1[digits[i]-'0'].length();
         }
        return res;
    }
};
