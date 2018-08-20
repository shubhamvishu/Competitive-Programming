//https://www.hackerrank.com/challenges/counter-game/problem

#include <bits/stdc++.h>

using namespace std;


string counterGame(long n)
{
  int x=0;

  while(n>1)
  {
    if((n&(n-1))==0)
    {
        n=n>>1;     
    }
    else{
       long t=n;
        t=t| (t>>1);
        t=t| (t>>2);
        t=t| (t>>4);
        t=t| (t>>8);
        t=t| (t>>16);
        t=t| (t>>32);
        n=n-((t+1)>>1);
       }
    x=x^1;
    
  }
    return (x==1)?"Louise":"Richard";
    
}

int main()
{
   

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0;i<t;i++)
    {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        cout << result << "\n";
    }

    return 0;
}

