//https://leetcode.com/problems/h-index-ii/

class Solution {

public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int hIndex(vector<int>& citations) {
        if(!citations.size()) return NULL;
        int l=0,h=citations.size()-1;
        while(l<h){
            int mid=(l+h)/2;
            if(mid!=h && min(citations[mid],citations.size()-mid)<=min(citations[mid+1],citations.size()-(mid+1)))
                l=mid+1;
            else h=mid;
        }
        return min(citations.size()-l,citations[l]);

    }
};
