//https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <bits/stdc++.h>

using namespace std;


string isBalanced(string s) {
if(s.length()%2!=0)
 return "NO";
 stack<char>s1;
 s1.push('*');
 for(int i=0;i<s.length();i++)
 {
     if(s[i]=='(' || s[i]=='[' || s[i]=='{')
     s1.push(s[i]);
     else {
         char x=s1.top(),y;
         if(s[i]==')')
          y='(';
          else if(s[i]==']')
          y='[';
          else if(s[i]=='}')
          y='{';

          if(x!=y)
          return "NO";
          else
           s1.pop();
     }
     
 }
 return s1.size()==1?"YES":"NO";

}

int main()
{

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}

