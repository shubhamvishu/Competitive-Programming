//https://leetcode.com/problems/01-matrix/

class Solution {
public:

    int minOfTwo(int a, int b){
        return a < b?a:b;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int N = mat.size(), M = mat[0].size();
        vector<vector<int>>v1(N,vector<int>(M));

        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                if(mat[i][j]==1) v1[i][j] = 10000007;
                else v1[i][j] = mat[i][j];
            }
        }

        for(int i = 0 ; i < N; i++){
            for(int j = 0 ; j < M; j++){
                 if(i-1>=0 && v1[i][j]!=0) v1[i][j] = minOfTwo(v1[i][j],v1[i-1][j]+1);
                 if(j-1>=0 && v1[i][j]!=0) v1[i][j] = minOfTwo(v1[i][j],v1[i][j-1]+1);
            }
        }

        for(int i = N-1 ; i >= 0; i--){
            for(int j = M-1 ; j >= 0; j--){
                 if(i+1<N && v1[i][j]!=0) v1[i][j] = minOfTwo(v1[i][j],v1[i+1][j]+1);
                 if(j+1<M && v1[i][j]!=0) v1[i][j] = minOfTwo(v1[i][j],v1[i][j+1]+1);
            }
        }
        return v1;
    }
};
