//https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;


string timeConversion(string s) {
   string s1;
    s1=s.substr(0,8);
    if(s[8]=='A')
    {  if(s[0]=='1' && s[1]=='2')
        { s1[0]='0',s1[1]='0';
           return s1;
         }
        
        return s1;
    }  
    else{
        if(s[0]=='1' && s[1]=='2')
            return s1;

        int a=s[1]-48,b=s[0]-48;
        int num=12+(10*b+a);
        s1[1]=(num%10)+48;
        num=num/10;
        s1[0]=(num%10)+48;
        return s1;
    }
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

