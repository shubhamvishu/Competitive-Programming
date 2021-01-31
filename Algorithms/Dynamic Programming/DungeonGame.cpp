//https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int mkh=0;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r=dungeon.size(),c=dungeon[0].size(),ans=1;
        vector<vector<int>>res(r,vector<int>(c,0));
        res[r-1][c-1]=max(-1*(dungeon[r-1][c-1])+1,1);
        for(int i=r-2;i>=0;i--)
            res[i][c-1]=max(res[i+1][c-1]-dungeon[i][c-1],1);
        for(int i=c-2;i>=0;i--)
            res[r-1][i]=max(res[r-1][i+1]-dungeon[r-1][i],1);
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                res[i][j]=max(min(res[i+1][j],res[i][j+1])-dungeon[i][j],1);
            }
        }
        return res[0][0];
    }
};
