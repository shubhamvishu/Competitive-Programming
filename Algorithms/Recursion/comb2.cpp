//To print all the palindrome combinations of size n from a array of numbers using
//each number from the array only once in a combination.
// (Frequency dependent palindrome combinations)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s,c=0;
vector<vector<int> >Vec;

bool ispalin(vector<int> v2)
{
  int i=0,j=v2.size()-1;
   while(i<j)
  { 
    if(v2[i]!=v2[j])
    return false;

    i++;
    j--;
  }

return true;
}

void allcomb(int a[],int n,int i,vector<int>v1,vector<bool>b)
{
  if(v1.size()>n)
    return;

  if(v1.size()<n)
  {
    v1.push_back(a[i]);
    b[i]=false;
  } 

  if(v1.size()==n)
  { 	if(ispalin(v1))
   	{
   		if(find(Vec.begin(),Vec.end(),v1)==Vec.end())
    		{    c++;
                     Vec.push_back(v1);
      		     for(int j=0;j<n;j++)
       		       cout<<v1[j];
      
      		      cout<<endl;
     		}
    	}

  }
 else{
        for(int k=0;k<s;k++)
        {
          if(b[k])
          allcomb(a,n,k,v1,b);    
        }  
     }
return;
   
}
 
int main()
{
  int a[10];
  cin>>s;
  vector<int>v;
  vector<bool>b(s,true);
  for(int i=0;i<s;i++)
  {
    cin>>a[i];
  }
  int n;
  cin>>n;
  for(int i=0;i<s;i++)
  {
    allcomb(a,n,i,v,b);
  }
  cout<<"Total no. of palindrome combinations using \neach no. only once(frequency dependent) from a array of numbers= "<<c<<endl;
  return 0;
}
