//https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    map<pair<int,int>,int>m1;

    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& visited){
        //cout<<i<<" "<<j<<endl;
        m1[{i,j}]=1;
        visited[i][j]=1;
        if(i-1>0 && !visited[i-1][j] && board[i-1][j]=='O') dfs(i-1,j,board,visited);
        if(i+1<board.size() && !visited[i+1][j] && board[i+1][j]=='O') dfs(i+1,j,board,visited);
        if(j-1>0 && !visited[i][j-1] && board[i][j-1]=='O') dfs(i,j-1,board,visited);
        if(j+1<board[0].size() && !visited[i][j+1] && board[i][j+1]=='O') dfs(i,j+1,board,visited);
    }
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        int m=board.size(),n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 ||j==0 ||i==m-1||j==n-1 ){
                    m1[{i,j}]=1;
                    if(board[i][j]=='O')
                        dfs(i,j,board,visited);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    if(i-1>0 && !m1[{i-1,j}]) board[i-1][j]='X';
                    if(i+1<m && !m1[{i+1,j}]) board[i+1][j]='X';
                    if(j-1>0 && !m1[{i,j-1}]) board[i][j-1]='X';
                    if(j+1<n && !m1[{i,j+1}]) board[i][j+1]='X';
                }
            }
        }
    }
};
