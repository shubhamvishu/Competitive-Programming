//https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        for(int i=0;i<pow(2,nums.size());i++){
            vector<int>v1;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j))
                    v1.push_back(nums[j]);
            }
            res.push_back(v1);
        }
        return res;
    }
};
