//https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>s1;
        set<long>::iterator it,itr;
        s1.insert(1);
        it=s1.begin();
        int count=0;
        while(count<=(n+1)){
            long x=*it;
            s1.insert(x*2);
            s1.insert(x*3);
            s1.insert(x*5);
            ++it;
            count++;

        }
        it=s1.begin();
        advance(it,n-1);
        return *it;
    }
};
