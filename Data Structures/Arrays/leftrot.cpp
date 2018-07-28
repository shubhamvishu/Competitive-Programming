//https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,c=0;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=d;c<n;)
    {
        cout<<a[i]<<" ";
        i=(i+1)%n;
        c++;
    }
    return 0;
}
