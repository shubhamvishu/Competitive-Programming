//https://www.hackerrank.com/challenges/bon-appetit/problem

#include <bits/stdc++.h>

using namespace std;


void bonAppetit(vector<int> bill, int k, int b) {
  int sum=0;
    for(int i=0;i<bill.size();i++)
    {
        sum+=bill[i];
    }
    sum-=bill[k];
    if((sum/2)!=b)
        cout<<(b-(sum/2));
    else
        cout<<"Bon Appetit";

}

int main()
{
    int n,k,a,b;
    cin>>n>>k;
    vector<int>bill(n);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        bill[i]=a;
    }

    cin>>b;
    bonAppetit(bill, k, b);

    return 0;
}


