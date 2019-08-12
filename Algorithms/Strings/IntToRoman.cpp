//https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string intToRoman(int num) {
        string number[][10]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"}, {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},{"","M","MM","MMM","MMMM"}};
        int t=num,x=0;
        string temp="";
        while(t>0)
        {
         
            int index=t%10;
            temp=number[x][index].append(temp);
            //v2.push_back(number[x][index]);
            x++;
            t/=10;
        }
        return temp;
    }
};
int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.intToRoman(n);
	return 0;
}
