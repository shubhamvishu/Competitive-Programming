//https://leetcode.com/problems/the-skyline-problem/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.size()<1) return {};
        unordered_map<int,vector<int>> inc,dec;
        multiset<int,greater <int>>s1;
        int maxx=0;
        vector<vector<int>>vec;
        for(auto v: buildings){
            if(v[1]>maxx) maxx=v[1];
            vec.push_back({v[0],1,v[2]});
            vec.push_back({v[1],2,v[2]});
        }
        sort(vec.begin(),vec.end(),[](const vector<int>& a,const vector<int>& b)         {
           if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int curr=vec[0][0],ch=-1;
        vector<vector<int>>res;
        for(int i=0;i<vec.size();){

            while(i<vec.size() && vec[i][0]==curr){
                if(vec[i][1]==2)
                    s1.erase(s1.find(vec[i][2]));
                else if(vec[i][1]==1)
                    s1.insert(vec[i][2]);
                i++;
            }
                int x=*s1.begin();
                if(x!=ch){
                    res.push_back({curr,x});
                    ch=x;
                }
            if(i>=vec.size()) break;
            curr=vec[i][0];
        }
        return res;
    }
};
