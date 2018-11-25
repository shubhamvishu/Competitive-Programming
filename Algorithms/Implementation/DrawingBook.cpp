//https://www.hackerrank.com/challenges/drawing-book/problem

#include <bits/stdc++.h>

using namespace std;

int pageCount(int n, int p) 
{

    int t,num,maxturn,min;
    if(n%2==0)
        t=(n/2)+1;
    else
        t=(n+1)/2;
    min=p/2;
    if(min>((t-1)-min))
        min=(t-1)-min;

    return min;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    cout << result << "\n";


    return 0;
}

