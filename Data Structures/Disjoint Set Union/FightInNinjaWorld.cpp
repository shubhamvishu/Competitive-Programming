//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/containers-of-choclates-1/

#include<bits/stdc++.h>
using namespace std;
void makesets(int point,int index,vector<int>& twosets,map<int,vector<int>>& m1,map<int,int>& visited){
    visited[point]=1;
    twosets[index]++;
    for(auto ele:m1[point]){
        if(!visited[ele]){
            makesets(ele,!index,twosets,m1,visited);
        }
    }
    return;
}
int solve(){
    int n,u,v;
    cin>>n;
    map<int,vector<int>>m1;
    map<int,int>visited;
    vector<pair<int,int>>input;
    for(int i = 0; i < n; i++){
        cin>>u>>v;
        input.push_back({u,v});
        m1[u].push_back(v);
        m1[v].push_back(u);
    }
    int res = 0;
    for(auto p: input){
        if(!visited[p.first]){
            vector<int> twosets = {0,0};
            makesets(p.first,0,twosets,m1,visited);
            res+=(twosets[0]<twosets[1])?twosets[1]:twosets[0];
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    n=t;
    while(t--){
        cout<<"Case "<<(n-t)<<": "<<solve()<<'\n';
    }
}
