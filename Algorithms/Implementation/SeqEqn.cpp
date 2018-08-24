//https://www.hackerrank.com/challenges/permutation-equation/problem

#include <bits/stdc++.h>

using namespace std;


vector<int> permutationEquation(vector<int> p) {
    
    vector<int>where((p.size()+1),0);
    for(int i=1;i<=p.size();i++)
    {
        where[p[i-1]]=i;
    }
    vector<int>v1;
    for(int i=1;i<=p.size();i++)
    {
        int x=where[i];
        v1.push_back(where[x]);
    }
  return v1;

}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<int> p(n);
    int a;
    for (int i = 0; i < n; i++) {
        cin>>a;

        p[i]=a;
    }

    vector<int> result = permutationEquation(p);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";
    return 0;
}


