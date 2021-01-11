//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int A[n][m];
        memset(A,0,sizeof(A));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0) A[i][j]=1;
                else A[i][j]+=A[i-1][j]+A[i][j-1];
            }
        }
        return A[n-1][m-1];

    }
};
