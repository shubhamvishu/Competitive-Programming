//https://www.hackerearth.com/fr/practice/data-structures/trees/heapspriority-queues/tutorial/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
void swap(ull *a,ull *b)
{
    ull t=*a;
    *a=*b;
    *b=t;
}
void maxheap(ull arr[],ull i)
{
    int l;
    if(arr[2*i]>arr[i])
        l=2*i;
    else l=i;    
    if(arr[2*i+1]>arr[l])
        l=2*i+1;
    if(l!=i)
    {
        swap(&arr[i],&arr[l]);
        maxheap(arr,l);
    }
}
void insertE(ull arr[],ull i)
{
    
    while(i>1 && arr[i/2]<arr[i])
    {
        swap(&arr[i/2],&arr[i]);
        i/=2;
    }
}
ull maxele(ull arr[])
{
    return arr[1];
}
int main()
{
    ull N;
    cin>>N;
    ull arr[1100005],len=N,a,b,q;
    for(ull i=1;i<=N;i++)
        scanf("%lld",&arr[i]);
    for(ull i=N/2;i>=1;i--)
    maxheap(arr,i);
    cin>>q;
    for(ull i=0;i<q;i++)
    {
        scanf("%lld",&a);
        if(a==1)
        {
            scanf("%lld",&b);
            ++len;
            arr[len]=b;
            insertE(arr,len);
        }
        else{cout<<endl;
            cout<<maxele(arr)<<endl;
        }
    }
}