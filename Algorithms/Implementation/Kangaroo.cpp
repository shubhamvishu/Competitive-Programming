//https://www.hackerrank.com/challenges/kangaroo/problem

#include <bits/stdc++.h>

using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) {
  int t1=x1,t2=x2;
    if( x1<x2 && v1<=v2)
        return "NO";
    int diff=x2-x1;
    int m=v1-v2;
    if(diff%m==0)
        return "YES";
    else
    return "NO";
}

int main()
{
    int x1,x2,v1,v2;
    cin>>x1>>x2>>v1>>v2;
    cout<<kangaroo(x1,x2,v1,v2);
    return 0;
}


