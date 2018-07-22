//https://www.hackerrank.com/challenges/two-characters/problem

#include <bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;
int istwo(vector<char>v2,char a,char b)
{
    vector<char>v3;
    int f=0;
    vector<char>::iterator it;
    for(int i=0;i<v2.size();i++)
    {it=find(v3.begin(),v3.end(),v2[i]);
        if(it==v3.end())
            v3.push_back(v2[i]);
        
    }
    if(v3.size()==2)
    {   
	  
    	for(int i=0;i<v2.size()-1 && f!=1;i++)
    	{   
    		if(v2[i]==v2[i+1])
    		 f=1;
		}
		
		if(f==1)
		 return 0;
		else 
		 return 1; 
	}
    else return 0;
    
}

int twoCharaters(string& s) {
      vector<char>c1;
      vector<char>v1;
     vector<char>::iterator it;
    string s1;
    int max=0;
    
    for(int i=0;i<s.length();i++)
    { 
	 it=find(c1.begin(),c1.end(),s[i]);
        if(it==c1.end())
           {
		   c1.push_back(s[i]);
           }
    }
  
   for(int i=0;i<c1.size()-1;i++)
   { s1=s;
   	 for(int j=i+1;j<c1.size();j++)
   	 {  
   	   for(int k=0;k<s1.length();k++)
   	   {    
   	   	     if(s1[k]==c1[i] || s1[k]==c1[j])
   	   	       {
   	   	       	  
				  v1.push_back(s1[k]);
   	   	       	  
					 }
		  }
   	
   	 	 if(istwo(v1,c1[i],c1[j])==1)
   	 	 {   
   	 	 	  if(v1.size()>max)
   	 	 	   { max=v1.size();
   	 	 	
					}
			 }
   	 	 v1.clear();
   	 	 
	 }
	 
   }
    return max;
}

int main() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    int result = twoCharaters(s);
    cout << result << endl;
    return 0;
}
