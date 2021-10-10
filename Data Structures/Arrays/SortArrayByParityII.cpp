//https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int ptr1 = 0, ptr2 = 1;
        while(ptr1 < nums.size() && ptr2 < nums.size()){
            while(ptr1 < nums.size() && nums[ptr1]%2==0) ptr1+=2;
            while(ptr2 < nums.size() && nums[ptr2]%2==1) ptr2+=2;
            if(ptr1 < nums.size() && ptr2 < nums.size()){
                int temp = nums[ptr1];
                nums[ptr1] = nums[ptr2];
                nums[ptr2] = temp;
            }
        }
        return nums;
    }
};
