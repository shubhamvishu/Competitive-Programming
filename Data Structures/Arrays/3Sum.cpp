//https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
    map<int,vector<int>>m1;
    map<pair<int,int>,int>visited;
    vector<vector<int>>res;
    sort(nums.begin(),nums.end());
    int n=nums.size();
	if(n < 3)
        return res;        
    for(int i = 0; i < n; i++){
        for(int j = i+1, k = n-1; j < k && i < k; ){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0 && !visited[{nums[i],nums[j]}]){
                
                vector<int>v1{nums[i],nums[j],nums[k]};
                res.push_back(v1);
                visited[{nums[i],nums[j]}]=1;
                j++;
            } else if (sum < 0){
                  j++;
            } else 
                   k--;
        }
    }
        //unique(res.begin(),res.end());
        return res;
    }
};
int main()
{
	Solution s;
	vector<int>v1;
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v1.push_back(a);	
	}	
	vector<vector<int>>res=s.threeSum(v1);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		cout<<res[i][j]<<" ";
		cout<<endl;
	}
	
}
