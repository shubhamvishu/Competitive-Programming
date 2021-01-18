//https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=31;i++){
            int c=0;
            for(int num:nums){
                if(num&(1<<i)) c++;
            }
            ans=ans|((c%3)<<i);
        }
        return ans;
    }
};
