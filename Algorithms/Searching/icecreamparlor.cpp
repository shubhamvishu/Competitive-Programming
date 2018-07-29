//https://www.hackerrank.com/challenges/icecream-parlor/problem

#include <bits/stdc++.h>

using namespace std;

vector<int> icecreamParlor(int m, vector<int> arr) {

    vector<int> v1;
    v1.clear();
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<m)
        {
            if(find(arr.begin(),arr.end(),(m-arr[i]))!=arr.end())
            {
                v1.push_back(i+1);
                bool f=false;
                for(int j=i+1;j<arr.size();j++)
                {
                    if(arr[j]==(m-arr[i]))
                    {
                        f=true;
                        v1.push_back(j+1);
                        break;
                    } 
                }
                if(!f)
                    v1.clear();
                else
                {sort(v1.begin(),v1.end());
                 break;
                }
            }
        }
    }
    return v1;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        vector<int>v,res;
        cin>>m;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        res=icecreamParlor(m,v);
        for(int i:res)
            cout<<i<<" ";
        cout<<endl;
    }
}

