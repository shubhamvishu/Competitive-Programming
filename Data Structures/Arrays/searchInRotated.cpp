//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        if(nums.size()==1) return (nums[0]==target)?0:-1;
        int begin=0,end=nums.size()-1,mid;
        while(begin<end){
            mid=(begin+end)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[begin]){
                if(target>=nums[begin] && target<nums[mid])
                    end=mid-1;
                else begin=mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[end])
                    begin=mid+1;
                else end=mid-1;
            }
        }
        return (nums[begin]==target)?begin:-1;
    }
    
};