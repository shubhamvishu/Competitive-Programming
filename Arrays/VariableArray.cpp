https://www.hackerrank.com/challenges/variable-sized-arrays/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n,q,k,**p,a,b;
    cin>>n>>q;
    p=new int*[n];
    for(int i=0;i<n;i++)
    {  cin>>k;
        p[i]=new int[k];
        for(int j=0;j<k;j++)
        {
            cin>>p[i][j];
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<p[a][b]<<endl;
    }
    return 0;
}
