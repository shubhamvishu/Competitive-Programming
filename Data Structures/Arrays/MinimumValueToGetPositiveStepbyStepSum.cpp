//https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minn = INT_MAX;
        for(auto num: nums){
            sum+=num;
            if(sum < minn) minn = sum;
        }
        if(minn >=1 ) return 1;
        else return (-1 * minn) +1;
    }
};
