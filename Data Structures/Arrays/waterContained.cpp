//https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findmin(int a,int b)
    {
        return a<b?a:b;
    }
    int maxWater(vector<int>& height) {
        vector<vector<int>>v1(height.size());
        int maxx=INT_MIN;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                if((j-i)*findmin(height[i],height[j])>maxx)
                {
                    maxx=(j-i)*findmin(height[i],height[j]);
                }
            }
        }
        return maxx;
    }
};
int main()
{
	int n,a;
	cin>>n;
	Solution s;
	vector<int>v1;              
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v1.push_back(a);
	}
	cout<<s.maxWater(v1);
	return 0;
}
