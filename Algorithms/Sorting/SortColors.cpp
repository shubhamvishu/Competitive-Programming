//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m1[3]={0,0,0};
        for(int i:nums) m1[i]++;
        for(int i=0;i<nums.size();i++){
            if(m1[0]) nums[i]=0;
            else if(m1[1]) nums[i]=1;
            else nums[i]=2;
            m1[nums[i]]--;
        }
    }
};
