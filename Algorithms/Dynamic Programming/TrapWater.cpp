//https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int minn(int a,int b)
    {
        return a<b?a:b;
    }
    int trap(vector<int>& height) {
        vector<int>right(height.size(),0),left(height.size(),0);
        if(height.size()<=2)
            return 0;
        left[0]=0;
        int sum=0;
        int max=height[0];
        for(int i=1;i<height.size();i++)
        {
            left[i]=max;
            if(height[i]>max)
                max=height[i];
        }
        right[height.size()-1]=0;
        max=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            right[i]=max;
            if(height[i]>max)
                max=height[i];
        }
        for(int i=1;i<height.size()-1;i++)
        {
            if((minn(left[i],right[i])-height[i])>0)
                sum+=minn(left[i],right[i])-height[i];
        }
        return sum;
    }
};