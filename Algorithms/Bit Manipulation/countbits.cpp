//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/count-the-bits/

#include <iostream>
#include<math.h>
 
using namespace std;
 
int main()
{
    
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int count=0;
        for(int i=0;i<(int)log2(n)+1;i++)
        {
            if(n & 1<<i)
             count++;
        }
        cout<<count<<endl;
    }
 
 
}
