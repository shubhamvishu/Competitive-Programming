//https://leetcode.com/problems/first-bad-version/

class Solution {
public:
    int firstBadVersion(int n) {
        long begin=1,end=n;
        while(begin<end){
            long mid=(begin+end)/2;
            if(isBadVersion(mid))
                end=mid;
            else{
                begin=mid+1;
            }
        }
        return begin;
    }
};
