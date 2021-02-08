//https://leetcode.com/problems/random-pick-with-weight/

class Solution {
public:
    vector<int>vec;
    int h;
    map<int,int>m1;
    Solution(vector<int>& w) {
       //vec.resize(w.size());
        int sum=0;
        for(int i=0;i<w.size();i++){
            sum+=w[i];
            m1[sum]=i;
            vec.push_back(sum);
        }
    }

    int pickIndex() {
        int num=rand()%vec.back()+1;
        int l=0,r=vec.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(vec[mid]<num) l=mid+1;
            else r=mid;
        }
        return m1[vec[r]];
    }
};
