//https://www.hackerrank.com/challenges/reduced-string/problem

#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
   string s1;
    s1.push_back(s[0]);
    
    for(int i=1;i<s.length();i++)
   {   if(s[i]!=s1[s1.length()-1])
         s1.push_back(s[i]);
      else
      {
          s1.pop_back();
      }
   }

    return s1;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    if(result.length()!=0)
    cout << result << endl;
    else
        cout<<"Empty String";
    return 0;
}
