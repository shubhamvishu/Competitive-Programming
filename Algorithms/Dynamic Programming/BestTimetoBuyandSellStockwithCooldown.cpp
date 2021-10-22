//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        vector<int>result(prices.size(),0);
        result[0]=0;
        if(prices.size()>1)    result[1]=max(0,prices[1]-prices[0]);
        if(prices.size()>2)    result[2]=max(0,max(result[1],max(prices[2]-prices[0],prices[2]-prices[1])));
        for(int i=3;i<prices.size();i++){
            for(int j=0;j<i;j++){
                if(j>=2) result[i]=max(result[i],max(result[i-1],prices[i]-prices[j]+result[j-2]));
                else result[i]=max(result[i],max(result[i-1],prices[i]-prices[j]));
            }
        }
        return result[prices.size()-1];
    }
};
