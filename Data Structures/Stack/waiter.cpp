//https://www.hackerrank.com/challenges/waiter/problem

#include <bits/stdc++.h>
using namespace std;

#define N 15000
vector<int>prime;

void getprimes()
{int isprime[N]={0};
 isprime[0]=1;
 isprime[1]=1;
 for(int i=2;i<(int)sqrt(N);i++)
 {
     for(int j=2;i*j<N;j++)
     {
         isprime[i*j]=1;
     }
 }
 for(int i=2;i<N;i++)
 {
     if(isprime[i]==0)
     {prime.push_back(i);} 
 }
    
}
void waiter(vector<int> number, int q) {
    getprimes();
    vector<int>a(number);
    vector<vector<int>>res;
    for(int m=1;m<=q;m++)
    { int x=prime[m-1];
     vector<int>b,temp;
    for(int i=a.size()-1;i>=0;i--)
    {  if(a[i]%x==0)
        {    b.push_back(a[i]);

        }
         else{
             temp.push_back(a[i]);
         }
    }
     for(int k=b.size()-1;k>=0;k--)cout<<b[k]<<endl;
     a.clear();
     a=temp;
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        cout<<a[i]<<endl;
    }

}

int main()
{
    int n,q,a;
    cin>>n>>q;
    vector<int>number;
   for(int i=0;i<n;i++)
   {   cin>>a;
       number.push_back(a);
   }
   waiter(number, q);
    return 0;
}


