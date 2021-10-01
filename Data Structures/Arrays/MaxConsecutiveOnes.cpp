//https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = 0;
        for(auto x : nums){
            if(x){
                count++;
                if(count > max) max = count;
            }
            else count = 0;
        }
        return max;
    }
};
