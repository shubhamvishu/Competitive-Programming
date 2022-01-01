//https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1 , r = n;
        while(l<r){
            auto mid = l + (r-l)/2;
            auto x = 1L * mid*(mid+1)/2;
            if(x == n) return mid;
            else if(x < n && (1L*(mid+1)*(mid+2)/2) > n) return mid;
            else if(x < n) l = mid+1;
            else r=mid-1;
        }
        return l;
    }
};
