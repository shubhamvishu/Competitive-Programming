//https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0

#include<bits/stdc++.h>
using namespace std;
int ma=0;

void maxtip(int a[],int b[],int x,int y,int i,int sum,int n)
{  //cout<<"n="<<n;
	if(i>n)
	return;
	if(sum>ma)
	{
	  ma=sum;
	}
	
	if(x>0)
	{
	  maxtip(a,b,x-1,y,i+1,sum+a[i],n);
	}
	if(y>0)
	maxtip(a,b,x,y-1,i+1,sum+b[i],n);
	
	return;
}

int main() {
	
	int t,a[1000],b[1000],n,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<n;i++)
		cin>>b[i];
	    maxtip(a,b,x,y,0,0,n);
	   cout<<ma<<endl;
	    ma=0;
	    
	}
	return 0;
}
