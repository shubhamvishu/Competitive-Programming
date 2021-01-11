//https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int R=word1.length()+1,C=word2.length()+1;
        int arr[R][C];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<R;++i) arr[i][0]=i;
        for(int i=0;i<C;++i) arr[0][i]=i;
        for(int i=1;i<R;i++){
            for(int j=1;j<C;j++){
                if(word1[i-1]==word2[j-1]) arr[i][j]=arr[i-1][j-1];
                else arr[i][j]=min(min(arr[i-1][j],arr[i][j-1]),arr[i-1][j-1])+1;
            }
        }
        return arr[R-1][C-1];
    }
};
