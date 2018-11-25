//https://www.hackerrank.com/challenges/sherlock-and-array/problem

#include <bits/stdc++.h>

using namespace std;

string balancedSums(vector<int> arr) 
{
 
    int a1[arr.size()],b1[arr.size()];
    for(int i=0;i<arr.size();i++)
    {
        if(i==0)
         a1[i]=0;
        else{
            a1[i]=a1[i-1]+arr[i-1];
        }
    }

    for(int i=arr.size()-1;i>=0;i--)
    {
        if(i==arr.size()-1)
         b1[i]=0;
        else{
            b1[i]=b1[i+1]+arr[i+1];
        }
    }
    for(int i=0;i<arr.size();i++)
    {
       if(a1[i]==b1[i])
           return "YES";
    }
    
    return "NO";
}

int main()
{
    int t,n,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }
        cout<<balancedSums(v)<<endl;
    }

    return 0;
}


