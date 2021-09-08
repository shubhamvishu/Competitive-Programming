//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        else if(nums.size()==1) return 1;
        int k=2;
        for(int i=2 ; i < nums.size(); i++){
            if(nums[i]!=nums[k-2]){
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};
