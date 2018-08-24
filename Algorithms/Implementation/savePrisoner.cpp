//https://www.hackerrank.com/challenges/save-the-prisoner/problem

#include <bits/stdc++.h>

using namespace std;

long saveThePrisoner(long n, long m, long s) {

    long x=(m%n);

   if(x==0)
   {
     if(s==1)
      return n;
      else
      return s-1;
   }
     if((x+s-1)>n)
     { 
         return (x+s)%n-1;
     }
    else{
        return (x+s)-1;
        }


}

int main()
{
   
    long t,n,m,s;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
         cin>>n>>m>>s;

        long result = saveThePrisoner(n, m, s);

        cout << result << "\n";
    }
    return 0;
}


