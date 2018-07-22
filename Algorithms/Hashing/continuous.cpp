//https://practice.geeksforgeeks.org/problems/check-if-array-contains-contiguous-integers-with-duplicates-allowed/0

#include<iostream>
#include <map>
#include<algorithm>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t>0)
	{
	    map<int,int>m1;
	    map<int,int>::iterator it=m1.begin(),itf=m1.begin();
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        m1[a[i]]++;
	    }
	    itf++;
	    int temp;
	    bool f=false;
	    for(it=m1.begin();it!=m1.end();it++)
	    {
	        if(it!=m1.begin())
	        {
	        	
	        	if((it->first)-temp>1 ||(it->first)-temp<0)
	        	{
	        		cout<<"No"<<endl;
	        		f=true;
	        		break;
	        	}
	        }
	        temp=it->first;
	       
	    }
	    if(!f)
	    cout<<"Yes"<<endl;
	    t--;
	}
	return 0;
}
