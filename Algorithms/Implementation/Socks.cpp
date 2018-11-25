//https://www.hackerrank.com/challenges/sock-merchant/problem

#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
   map<int,int>m1;
   map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        m1[ar[i]]++;
    }
    int pairs=0;
    for(it=m1.begin();it!=m1.end();it++)
    {
        pairs+=(it->second)/2;
        
    }
    return pairs;

}

int main()
{
   
    int n,a;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        cin>>a;
        ar[i] = a;
    }

    int result = sockMerchant(n, ar);

    cout << result << "\n";


    return 0;
}


