//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=1;
        while(i<nums.size() && nums[i]>=nums[i-1]) i++;
        if(i<=nums.size()-1) return nums[i];
        return nums[0];
    }
};
