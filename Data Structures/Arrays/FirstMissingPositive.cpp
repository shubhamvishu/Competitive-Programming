//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    void swapNumber(long x,int index, vector<int>& nums,int inf){
        if((x-1)>=0 && (x-1)<=nums.size()-1){
            int temp = nums[x-1];
            nums[x-1] = nums[index];
            nums[index] = temp;
            if(nums[index]!=index+1 && inf!=nums[index])
                swapNumber(nums[index],index,nums,nums[index]);
        }
        return;
    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=i+1)
                swapNumber(nums[i],i,nums,INT_MAX);
        }
        int fmp = 1;
        for(auto x: nums){
            if(x!=fmp) return fmp;
            else fmp++;
        }
        return fmp;
    }
};
