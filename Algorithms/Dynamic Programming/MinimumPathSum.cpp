//https://leetcode.com/problems/minimum-path-sum/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>sum(grid);
        int w=grid.size(),h=grid[0].size();
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                int a=1e7,b=1e7;
                if(range(i-1,j,w,h)) a=sum[i-1][j];
                if(range(i,j-1,w,h)) b=sum[i][j-1];
                sum[i][j]=sum[i][j]+min(a,b);
                if(i==0 && j==0) sum[i][j]=grid[i][j];
            }
        }
        return sum[w-1][h-1];
    }
    bool range(int i,int j,int w,int h){
        return 0<=i && i<w && 0<=j && j<=h;
    }
};
