//https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        if(!nums.size()) return {};
        sort(nums.begin(),nums.end());
        vector<int>arr(nums.size(),1);
        vector<vector<int>> res(nums.size());
        int maxx=INT_MIN,index=-1;

        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            res[i].push_back(nums[i]);
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && arr[j]+1>=arr[i]){
                    arr[i]=arr[j]+1;
                    temp=res[j];
                }
            }
            if(arr[i]>maxx){
                maxx=arr[i];
                index=i;
            }
            res[i].insert(res[i].end(),temp.begin(),temp.end());
        }
        reverse(res[index].begin(),res[index].end());
        return res[index];
    }
};
