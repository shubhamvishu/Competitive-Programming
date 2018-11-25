//https://www.hackerrank.com/challenges/lonely-integer/problem

#include <bits/stdc++.h>

using namespace std;


int lonelyinteger(vector<int> a) 
{
  
  int n=0;
  vector<int>v1(100,0);
    for(int i:a)
    {
        v1[i]=v1[i]^1;   
      
    }
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i]==1)
         return i;
    }
    return -1;

}

int main()
{
    int n,a;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<lonelyinteger(v);
    return 0;
}


