//https://www.hackerrank.com/challenges/maxsubarray/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,a;
    cin>>t;
    while(t--)
    {    int sum=0,max=INT_MIN,max1=INT_MIN,max2=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a>max) max=a;
            if(a>0)   max2+=a;
            if((sum+a)>=0)
             sum+=a;
            else
             sum=0;
             if(sum>max1)max1=sum;
        }
        if(max<0)
         {max2=max;
          max1=max;
         }
         cout<<max1<<" "<<max2<<endl;


    }        

    return 0;
}


