//https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    bool b=false;
    int minP;
    int dp[105][105];
    void cheap(int A[][105],vector<int>visited,vector<vector<int>>& adj,int src,int dst,int k,int cost){
        if(k<-1) return;
        if(src==dst){
            b=true;
            if(cost<minP){
                minP=cost;
                return;
            }
        }
        visited[src]=1;
        for(int i:adj[src]){
            if(!visited[i] && cost+A[src][i]<=minP)
            cheap(A,visited,adj,i,dst,k-1,cost+A[src][i]);
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src==dst) return 0;
        int A[105][105];
        vector<int>visited(105);
        memset(A,INT_MAX,sizeof(A));
        vector<vector<int>>adj(n);
        for(auto v:flights){
            adj[v[0]].push_back(v[1]);
            A[v[0]][v[1]]=v[2];
        }
        for(int i=0;i<n;i++) A[i][i]=0;
        minP=INT_MAX;
        cheap(A,visited,adj,src,dst,K,0);
        return b==false?-1:minP;

    }
};
