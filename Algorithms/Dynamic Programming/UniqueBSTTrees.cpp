//https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        vector<int>v1(n+1,1);
        v1[0]=1;
        v1[1]=1,v1[2]=2;
        for(int i=3;i<=n;i++){
            int sum=0;
            for(int j=1;j<=i;j++){
                sum+=(v1[j-1]*v1[i-j]);
            }
            v1[i]=sum;
        }
        return v1[n];
    }
};
