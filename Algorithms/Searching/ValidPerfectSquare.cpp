//https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        double n=double(num/2.0),b=0,e=num;
        while(abs(double(n*n)-num)>1e-2){
            if((n*n)>num)
                e=n;
            else b=n;
            n=(b+e)/2;
            if(n*n==num) return true;

        }
        return floor(n)*floor(n)==num || ceil(n)*ceil(n)==num;
    }
};
