//https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size()==0)
            return vector<vector<int>>{};
        sort(nums.begin(),nums.end());
        map<int,vector<pair<int,int>>>m1;
        vector<vector<int>>res;
        vector<vector<int>>::iterator it;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                m1[nums[i]+nums[j]].push_back({i,j});
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                for(pair<int,int>p:m1[target-(nums[i]+nums[j])])
                {
                    if(p.first>j && p.second>j)
                    {
                        vector<int>v1={nums[i],nums[j],nums[p.first],nums[p.second]};    
                         res.push_back(v1);
                        
                    }
                }
            }
        }
        it=unique(res.begin(),res.end());
        res.resize(distance(res.begin(),it));
        return res;
    }
};
