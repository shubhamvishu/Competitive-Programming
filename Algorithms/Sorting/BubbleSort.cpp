//https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/bubble-sort-15-8064c987/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    bool f=true;
    int count=0;
    while(f){
        f=false;
        count++;
        for(int i=0;i<n-1;i++){
            if(v1[i]>v1[i+1]){
                int temp=v1[i];
                v1[i]=v1[i+1];
                v1[i+1]=temp;
                f=true;
            }
        }
    }
    cout<<count<<endl;
}
