//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0,reach=0;
        for(i=0;i<=reach;i++){
            reach=max(reach,i+nums[i]);
            if(reach>=nums.size()) return true;
        }
        return reach==nums.size()-1;
    }
};