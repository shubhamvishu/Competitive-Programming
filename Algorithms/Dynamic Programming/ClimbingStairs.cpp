//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for(int i = 1; i <= 45; i++){
            int ans = a + b;
            a = b;
            b = ans;
            if(i==n) return ans;
        }
        return 1;
    }
};
