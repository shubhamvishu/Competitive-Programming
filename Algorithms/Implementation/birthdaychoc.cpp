//https://www.hackerrank.com/challenges/the-birthday-bar/problem

#include <bits/stdc++.h>

using namespace std;

int birthday(vector<int> s, int d, int m) 
{
    int sum=0,count;
    for(int i=0;i<m;i++)
    {
        sum+=s[i];
    }
    if(sum==d) 
        count++;
    for(int i=m;i<s.size();i++)
    {
        sum+=s[i];
        sum-=s[i-m];
        if(sum==d)
            count++;
    }
    return count;
    

}

int main()
{
    int n,a,d,m;
    vector<int>v;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cin>>d>>m;
    int res=birthday(v,d,m);
    cout<<res;

    return 0;
}


