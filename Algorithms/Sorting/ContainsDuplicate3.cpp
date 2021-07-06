//https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>>v1;
        if(nums.size()<2) return false;
        for(int i=0;i<nums.size();i++){
            v1.push_back({nums[i],i});
        }
        sort(v1.begin(),v1.end());
        int i=0,j=0;
        while(i<nums.size()-1 && j<=nums.size()-1){
            long n1=v1[i].first,n2=v1[j].first;
            if(abs(n1-n2)<=t && abs(v1[i].second-v1[j].second)<=k && i!=j){
                return true;
            }
            else if(abs(n1-n2)>t){
                i++;
                j=i;
            }
            else j++;
        }
        return false;
    }
};
