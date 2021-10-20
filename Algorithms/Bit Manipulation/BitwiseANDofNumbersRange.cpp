//https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int min(int a, int b){
        return a<b?a:b;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        int ans = 0,temp = left, lcnt = 0,rcnt = 0,max_right = -1+pow(2,31);
        while(temp){
            lcnt++;
            temp>>=1;
        }
        temp = right;
        while(temp){
            rcnt++;
            temp>>=1;
        }
        if(lcnt!=rcnt) return 0;
        else{
                if(rcnt == 31) max_right = pow(2,31)-1;
                else max_right = 1<<rcnt;
                for(int i = left; i <= min(right,max_right); i++){
                    if(i == left) ans = left;
                    else ans&=i;
                    if(!ans) break;
                    if(i == right) break;
                }
        }

        return ans;
    }
};
