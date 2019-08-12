//https://leetcode.com/problems/3sum-closest/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int abs(int a,int b)
    {
        if((a-b)<0)
            return (a-b)*-1;
        return (a-b);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int ans,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int sum=nums[i]+nums[j];
                int x=target-sum;
                int a=j+1,b=nums.size()-1;
                while(a<=b)
                {
                    int mid=(a+b)/2;
                    if(abs(target,sum+nums[mid])<diff)
                    {
                        diff=abs(target,sum+nums[mid]);
                        ans=sum+nums[mid];
                        if(diff==0)
                            return target;
                    }
                    if(nums[mid]>x)
                        b=mid-1;
                    else a=mid+1;;
                }
            }
        }
        return ans;
    }
    
};
int main()
{
	Solution s;
	vector<int>v1;
	int n,a,target;
	cin>>n>>target;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v1.push_back(a);	
	}	
	cout<<s.threeSumClosest(v1,target);
	return 0;
	
}
