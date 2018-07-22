//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/hash-table-content-problem-1/

#include <iostream>
#include<vector>
using namespace std;
 
int hashfunc(int r)
{
    return r%19;
}
struct student{
    int rno;
    string name;
};
 
 
 
int main() 
{
	int n,index;
	cin>>n;
	vector<vector<student>>v1(20);
	student s;
	for(int i=0;i<n;i++)
	{
	    cin>>s.rno>>s.name;
	    index=hashfunc(s.rno);
	    v1[index].push_back(s);
	    
	}
	int q,x;
	cin>>q;
	for(int i=0;i<q;i++)
	{
	    cin>>x;
	    index=hashfunc(x);
	    for(int j=0;j<v1[index].size();j++)
	    {
	        if(v1[index][j].rno==x)
	         cout<<v1[index][j].name<<endl;
	    }
	    
	}
}
