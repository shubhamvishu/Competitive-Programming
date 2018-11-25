//https://www.hackerrank.com/challenges/missing-numbers/problem

#include <bits/stdc++.h>

using namespace std;


vector<int> missingNumbers(vector<int> arr, vector<int> brr) 
{
    map<int,int>m1;
    map<int,int>::iterator it;

    vector<int>v1;

    for(int i=0;i<arr.size();i++)
    {
        m1[arr[i]]++;
    }
    for(int i=0;i<brr.size();i++)
    {
        m1[brr[i]]--;
    }
    for(it=m1.begin();it!=m1.end();it++)
    {
        if(it->second!=0)
            v1.push_back(it->first);
    }
    return v1;

}

int main()
{
    int n,m,a;
    cin>>n;
    vector<int>v1;
    for(int i=0;i<n;i++)
    {
       cin>>a;
       v1.push_back(a);
    }
    cin>>m;
    vector<int>v2;
    for(int i=0;i<m;i++)
    {
       cin>>a;
       v2.push_back(a);
    }
    vector<int>res=missingNumbers(v1,v2);
    for(int i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}


