//https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res;
        res.push_back(0);
        int curr=1;
        for(int i=1;i<=num;i++){
            res.push_back(res[i&(i-1)]+1);
        }
        return res;
    }
};
