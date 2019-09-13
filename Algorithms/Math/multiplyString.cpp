//https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
    vector<int>v1(num1.size()+num2.size(),0);
        int pos1=0,pos2=0;
        if(num1=="0" || num2=="0")
            return "0";
       for(int i=num1.length()-1;i>=0;i--)
       {
           int carry=0;
           int n1=num1[i]-'0';
           pos2=0;
           for(int j=num2.length()-1;j>=0;j--)
           {
            
               int n2=num2[j]-'0';
               int x=n1*n2+v1[pos1+pos2]+carry;
               carry=x/10;
               v1[pos1+pos2]=x%10;
               pos2++;
               
           }
           if(carry>0)
           {
               v1[pos1+pos2]+=carry;
           } 
           pos1++;
       }
        int i=v1.size()-1;
        while(v1[i]==0)
        {
            i--;
        }
        string res;
        for(;i>=0 ;i--)
        {
            string add(1,v1[i]+'0');
            res.append(add);
        
        }
        return res;
    }
};