//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/favorite-subsequence-1-3a9b26d4/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    map<char,long>m1;
    string str;
    cin>>str;
    for(char c:str){
        switch(c){
            case 'a':m1[c]=(2*m1[c]+1)%MOD;break;
            case 'b':m1[c]=(2*m1[c]+m1[c-1])%MOD;break;
            case 'c':m1[c]=(2*m1[c]+m1[c-1])%MOD;break;
        }
    }
    cout<<m1['c'];
}