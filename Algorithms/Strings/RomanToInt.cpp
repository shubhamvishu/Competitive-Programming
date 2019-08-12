//https://leetcode.com/problems/roman-to-integer/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        map<string,int>m1={{"I",1},{"II",2},{"III",3},{"IV",4},{"V",5},{"VI",6},{"VII",7},{"VIII",8},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
        int sum=0;
        while(s!="")
        {
            string temp=s;
            for(int i=0;i<temp.length();i++)
            {
                if(m1[temp.substr(i)])
                {   sum+=m1[temp.substr(i)];
                    s=s.substr(0,i);
                    break;
                }
            }
        }
        return sum;
    }
};

int main()
{
	string str;
	Solution s;
	cin>>str;
	cout<<s.romanToInt(str);
	return 0;
}
