//https://www.hackerrank.com/challenges/magic-square-forming/problem

#include <bits/stdc++.h>

using namespace std;
int diff(int a[],int b[])
{  int sum=0;
    for(int i=0;i<8;i++)
    {
        sum+=abs(a[i]-b[i]);
    }
   return sum;
}


int formingMagicSquare(vector<vector<int>> s) 
{
  
  int a[8]={4,9,2,7,6,1,8,3};
  int a2[8]={4,3,8,1,6,7,2,9};
  int b[8]={s[0][0],s[0][1],s[0][2],s[1][2],s[2][2],s[2][1],s[2][0],s[1][0]};
    int min=0,d,t1,t2;
    for(int i=0;i<8;i++)
    {
        if(i==0)
        {min=diff(a,b);
         cout<<min<<" ";
        }
        else{
            d=diff(a,b);
            //cout<<diff<<" ";
            if(d<min)
                min=d;
            d=diff(a2,b);
            if(d<min)
                min=d;
            t1=b[0],t2=b[1];
            for(int i=0;i<6;i++)
            {
                b[i]=b[i+2];
            }
            b[6]=t1;
            b[7]=t2;
        }
         
    
    }
    min+=abs(5-s[1][1]);
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

