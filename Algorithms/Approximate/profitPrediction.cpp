//https://www.hackerearth.com/challenges/competitive/akamai-coding-edge-2019/problems/7396254213f84fe59beabab05d923ae4/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1003
vector<int>visited(MAX,0);
vector<vector<int>>v1(MAX);
map<pair<int,int>,int>m1;
map<pair<int,int>,double>m2;
double cost=0;
void dfs(int node,long curr,double p){
    visited[node]=1;
    bool b=false;
    for(int i=0;i<v1[node].size();i++){
        if(!visited[v1[node][i]]){
            b=true;
            dfs(v1[node][i],curr+m1[{node,v1[node][i]}],p*m2[{node,v1[node][i]}]);
        }
    }
    if(!b){
        cost+=(curr*p);
    }
}
int main(){
    int n,u,v,d;
    double p;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>d>>p;
        v1[u].push_back(v);
        v1[v].push_back(u);
        m1[{u,v}]=d;
        m2[{u,v}]=p;
    }
    visited[1]=1;
    for(int i=0;i<v1[1].size();i++){
        if(!visited[v1[1][i]]);
        dfs(v1[1][i],m1[{1,v1[1][i]}],m2[{1,v1[1][i]}]);
    }
    cout<<cost;
}