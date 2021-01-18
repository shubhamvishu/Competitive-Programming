//https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int v=0;
        for(int a:nums){
            v^=a;
        }
        return v;
    }
};
