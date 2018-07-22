//https://www.hackerrank.com/challenges/strong-password/problem

#include <bits/stdc++.h>

using namespace std;

int minimumNumber(int n, string password) {
    int count=0,f1=0,f2=0,f3=0,f4=0,x;
    for(int i=0;i<password.length();i++)
    {    int n=password[i];
        if(n>=65 && n<=90 && f1==0)
        {  count++;f1=1;}
     if(n>=97 && n<=122 && f2==0)
        {  count++;f2=1;}
     if(n>=33 && n<=45 && f3==0)
        {  count++;f3=1;}
     if(n>=48 && n<=57 && f4==0)
        {  count++;f4=1;}
     
    }
    x=4-count;
    if(password.length()>=6)
      return x;
    else{
        if((6-password.length())>=x)
            return 6-password.length();
        else
            return x;
    }
              
}

int main() {
    int n;
    cin >> n;
    string password;
    cin >> password;
    int answer = minimumNumber(n, password);
    cout << answer << endl;
    return 0;
}
