//https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem

#include <bits/stdc++.h>

using namespace std;

vector<int> breakingRecords(vector<int> scores) 
{
    
    int low=scores[0],high=scores[0],h=0,l=0;
    vector<int>v1;
    for(int i=1;i<scores.size();i++)
    {
        if(scores[i]>high)
        {  h++;
         high=scores[i];
        }
        else if(scores[i]<low)
        {   l++;
          low=scores[i];
        }
    }
    
    v1.push_back(h);
    v1.push_back(l);
    return v1;
    

}

int main()
{
    

    int n,a;
    vector<int>v,res;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    res=breakingRecords(v);
    for(int i:res)
    {
        cout<<i<<" ";
    }
    
    return 0;
}


