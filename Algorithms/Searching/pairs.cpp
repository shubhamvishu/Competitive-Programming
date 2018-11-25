//https://www.hackerrank.com/challenges/pairs/problem

#include <bits/stdc++.h>

using namespace std;

int pairs(int k, vector<int> arr) 
{

    map<int,int>m1;
    map<int,int>::iterator it;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        m1[arr[i]]=1;
    }
    for(int i=0;i<arr.size();i++)
    { 
        if(m1[arr[i]+k]==1)
            count++;
    }
    return count;
}

int main()
{
   
    int n,k,a;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<pairs(k,v);
    return 0;
}


