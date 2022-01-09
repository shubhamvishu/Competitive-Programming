//https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xo=0;
        for(int i:nums){
            xo^=i;
        }
        int x=0,xor1=0,xor2=0;
        while(!(xo&(1<<x))){x++;}
        for(int i:nums){
            if(i&(1<<x)) xor1^=i;
            else xor2^=i;
        }
        return {xor1,xor2};
    }
};
