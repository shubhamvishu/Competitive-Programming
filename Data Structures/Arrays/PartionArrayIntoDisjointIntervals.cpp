//https://leetcode.com/problems/partition-array-into-disjoint-intervals/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        vector<int>v1(len,0),v2(len,0);
        int currmax=nums[0];
        for(int i=0;i<len;i++){
            if(currmax>=nums[i]){
                v1[i]=currmax;
            }
            else{
                currmax=nums[i];
                v1[i]=nums[i];
            }
        }
        currmax=nums[len-1];
        for(int i=len-1;i>=0;i--){
            if(currmax<=nums[i]){
                v2[i]=currmax;
            }
            else{
                currmax=nums[i];
                v2[i]=nums[i];
            }
        }
        for(int i=0;i<len-1;i++){
            if(v1[i]<=v2[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};
