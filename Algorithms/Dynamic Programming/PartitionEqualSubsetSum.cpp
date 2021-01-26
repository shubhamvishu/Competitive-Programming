//https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        queue<int>q;
        unordered_map<int,int>m1;
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum&1) return false;
        int sum2=0;
        sort(nums.begin(),nums.end());
        vector<int>vec;
        for(int i=0;i<nums.size() && nums[i]<=(sum/2);i++){
            sum2+=nums[i];
            int x=vec.size();
            for(int j=0;j<x;j++){
                if(!m1[nums[i]+vec[j]]) {
                    m1[nums[i]+vec[j]]=1;
                    vec.push_back(nums[i]+vec[j]);
                }
            }
            if(!m1[nums[i]]) {
                m1[nums[i]]=1;
                vec.push_back(nums[i]);
            }

        }
        return m1[sum/2];
    }
};
