//https://www.hackerrank.com/challenges/maximum-element/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;


int main() {
    stack<int> s1;
    stack<int> s2;
    int maxx=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int x;
            cin>>x;
            if(s1.empty() && s2.empty())
            {
              s1.push(x);
              s2.push(x);
            }
            else
            {
                s1.push(x);
                if(x>s2.top())
                 s2.push(x);
                 else
                 s2.push(s2.top());
            }     
        }
        else if(a==2)
        {   
            s1.pop();
            s2.pop();    
        }
        else if(a==3)
        {
            cout<<s2.top()<<endl;
        }
    }
    return 0;
}

