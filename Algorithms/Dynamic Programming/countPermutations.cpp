//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/little-jhool-and-too-many-products-29fb5474/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009

int main(){
    int t,a,s;
    vector<vector<int>>mat(1001,vector<int>(1001,0));
    cin>>t;
    for(int i=0;i<1001;i++)
    mat[i][1000]=0;
    mat[0][1000]=1;
    for(int i=999;i>0;i--){
        for(int j=0;j<1000;j++){
            mat[j][i]=mat[j][i+1];
            if(j-i>=0){
                mat[j][i]=(mat[j][i]+mat[j-i][i])%MOD;
            }
        }
    }
    while(t--){
        cin>>a>>s;
        cout<<mat[a][s]<<endl;
    }
}