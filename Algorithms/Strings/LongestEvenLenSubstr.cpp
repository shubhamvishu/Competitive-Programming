//https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0

#include <iostream>
using namespace std;

int main() {
	
	string str;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>str;
		int sum=0;
		vector<int>v1(str.length()+1,0);
		for(int j=1;j<=str.length();SSSj++)
		{
			v1[j]=v1[j-1]+(str[j-1]-'0');
	
		}

		int start=1,end,maxx=0,f=0;
		for(int m=start;m<str.length()-maxx;m++)
		{
			end=((str.length()-m+1)%2==0)?str.length():str.length()-1;
			//cout<<m<<" "<<end<<endl;
			for(int n=end;n>m && (n-m+1)>maxx;n-=2)
			{
				int mid=(m+n)/2;
				//cout<<"  "<<mid<<endl;
				if((v1[mid]-v1[m-1])==(v1[n]-v1[mid]))
				{
					maxx=(n-m+1);
					if(maxx==str.length() || maxx==str.length()-1)
				     f=1;
					break;
				}
			}
			if(f) break;
		}
		cout<<maxx<<endl;
	}
	return 0;
}
