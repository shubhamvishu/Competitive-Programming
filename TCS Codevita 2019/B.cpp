#include<bits/stdc++.h>
using namespace std;
bool f=false;
int minn=INT_MAX;

long convertNum(list<long>l1)
{
   list<long>::reverse_iterator it;
   long num=0,i=0;
   for(it=l1.rbegin();it!=l1.rend();it++)
   {
   	   num=num+((*it)*pow(10,i));
   	   i++;
   }
   return num;
}
long findNext(long a,long b,int index,string s,map<long,long>m1,list<long>l1,int d)
{
	map<long,long>::iterator it;
	
	if(d==1)
	{
		list<long>::iterator litr;
		for(it=m1.begin();it!=m1.end();it++)
		{
			for(int i=0;i<it->second;i++)
			{
				l1.push_back(it->first);
			}
		}
		litr=l1.begin();
		long num=convertNum(l1);
		if(num<=b)
		 {
		 	return -1;
		 }
		 else
		 return num;
		
	}
	if(index==s.length())
	{
		long num=convertNum(l1);
		if(num<=b)
		 {
		 	//cout<<"Wrong"<<endl;
		 	return -1;
		 }
		 else
		 return num;
	}
	
	it=m1.lower_bound(s[index]-'0');
	long temp=0;
	for(auto itr=it;itr!=m1.end();itr++)
	{
		if(itr->first==(s[index]-'0') && itr->second>0){
			m1[itr->first]--;
			l1.push_back(itr->first);
			temp=findNext(a,b,index+1,s,m1,l1,0);
			m1[itr->first]++;
			l1.pop_back();
			if(temp!=-1)
			 return temp;
		}
		else if(itr->first>(s[index]-'0') && itr->second>0){
			m1[itr->first]--;
			l1.push_back(itr->first);
			temp=findNext(a,b,index+1,s,m1,l1,1);
			m1[itr->first]++;
			l1.pop_back();
			if(temp!=-1)
			 return temp;
		}
	}
	return -1;
	
}
int main()
{
	long a,b,t1,t2,digit=0;
	string s1,s2;
	cin>>a>>b;
	map<long,long>m1,m2;
	list<long>l1;
	t1=a;
	t2=b;
	while(t1>0)
	{
		m1[t1%10]++;
		t1/=10;
	}
	while(t2>0)
	{
		m2[t2%10]++;
		t2/=10;
	}
	stringstream ss;
	ss<<a;
	ss>>s1;
	ss.clear();
	ss<<b;
	ss>>s2;
	long ans=findNext(a,b,0,s2,m1,l1,0);
	if(ans)
	cout<<ans<<endl;
	else
	cout<<"-1"<<endl;
	return 0;
}
