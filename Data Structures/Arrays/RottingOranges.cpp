//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>v1;
        int ans=0,noo=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) noo++;
                if(grid[i][j]==2){
                    v1.push_back({i,j});
                }
            }
        }
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>days(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        for(auto x:v1){
            days[x.first][x.second]=0;
            queue<pair<int,int>>q;
            q.push({x.first,x.second});
            while(!q.empty()){
                auto y=q.front();
                q.pop();
                if(y.first-1>=0 && days[y.first][y.second]+1<days[y.first-1][y.second] && grid[y.first-1][y.second]==1)
                {
                    days[y.first-1][y.second]=days[y.first][y.second]+1;
                    q.push({y.first-1,y.second});
                }
                if(y.first+1<grid.size() && days[y.first][y.second]+1<days[y.first+1][y.second] && grid[y.first+1][y.second]==1)
                {
                    days[y.first+1][y.second]=days[y.first][y.second]+1;
                    q.push({y.first+1,y.second});
                }
                if(y.second-1>=0 && days[y.first][y.second]+1<days[y.first][y.second-1] && grid[y.first][y.second-1]==1)
                {
                    days[y.first][y.second-1]=days[y.first][y.second]+1;
                    q.push({y.first,y.second-1});
                }
                if(y.second+1<grid[0].size() && days[y.first][y.second]+1<days[y.first][y.second+1] && grid[y.first][y.second+1]==1)
                {
                    days[y.first][y.second+1]=days[y.first][y.second]+1;
                    q.push({y.first,y.second+1});
                }
            }
        }
        vector<int>v2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) noo++;
                if(grid[i][j]==1 && days[i][j]==INT_MAX){
                    return -1;
                }
                else if(grid[i][j]==1){
                     v2.push_back(days[i][j]);
                }
            }
        }
        if(v2.size()<1) return 0;
        sort(v2.begin(),v2.end());

        return v2[v2.size()-1];
    }
};
