//https://www.hackerrank.com/challenges/between-two-sets/problem

#include <bits/stdc++.h>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
   
    int temp[b[0]+1]={0};
    vector<int>v1;
    for(int i=0;i<a.size();i++)
   {
       for(int j=1;a[i]*j<=b[0];j++)
       {
           temp[a[i]*j]++;
      
       }
   }
    for(int i=0;i<=b[0];i++)
    {
        if(temp[i]==a.size())
        {   v1.push_back(i);
        }
    }
    int count=0;
    for(int i=0;i<v1.size();i++)
    {
        bool f=true;
        for(int j=0;j<b.size();j++)
        {
            if(b[j]%v1[i]!=0)
            {
                f=false;
                break;
            }
        }
        if(f)
            count++;
    }
    return count;
}

int main()
{
    int n,m,num1,num2;
    cin>>n>>m;
    
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        cin>>num1;
        a.push_back(num1);
    }

    vector<int>b;
    for(int i=0;i<m;i++)
    {
        cin>>num2;
        b.push_back(num2);

    }
    cout<<getTotalX(a,b);
    return 0;
}


