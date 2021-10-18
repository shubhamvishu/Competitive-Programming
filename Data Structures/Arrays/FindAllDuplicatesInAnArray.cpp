//https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        for(int num : nums ){
            int index = abs(num);
            if(nums[index-1] < 0){
                result.push_back(index);
            }
            else nums[index-1]*=-1;
        }
        return result;
    }
};
