//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/color-the-boxes-47270a3b/submissions/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    unsigned long long m,n,ans=1;
    cin>>m>>n;
    for(unsigned long long i=n;i>=2;i--)
    ans=(ans*i)%MOD;
    cout<<ans%MOD;
    return 0;
}