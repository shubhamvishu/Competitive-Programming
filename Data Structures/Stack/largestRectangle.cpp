//https://www.hackerrank.com/challenges/largest-rectangle/problem

#include <bits/stdc++.h>
#include <stack>
#include<algorithm>
using namespace std;
int maxH=0;

long largestRectangle(vector<int> h) {
    stack<int> s;
    s.push(-1);
    int i;
    for(i=0;i<h.size();i++)
    {
        if(s.top()!=-1 && h[i]<h[s.top()])
        {
            while(h[s.top()]>h[i])
            {
                int he=h[s.top()];
                s.pop();
                int we=i-s.top()-1;
                maxH=max(maxH,he*we);
                //cout<<"maxH="<<maxH;
            }
        }
            s.push(i);
            //cout<<"i="<<i<<" ";
    
    }
    while(!s.empty())
    {
        int he=h[s.top()];
        s.pop();
        int we;
        if(!s.empty())
         we=h.size()-s.top()-1;
        maxH=max(maxH,he*we);
    }
    return maxH;
}

int main()
{
    
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int>v1(n);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }

    cout<<largestRectangle(v1);

    return 0;
}

