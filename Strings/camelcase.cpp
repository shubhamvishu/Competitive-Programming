//https://www.hackerrank.com/challenges/camelcase/problem

#include <bits/stdc++.h>

using namespace std;

int camelcase(string s) {
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(isupper(s[i]))
            count++;
    }
    return count+1;
}

int main() {
    string s;
    cin >> s;
    int result = camelcase(s);
    cout << result << endl;
    return 0;
}
