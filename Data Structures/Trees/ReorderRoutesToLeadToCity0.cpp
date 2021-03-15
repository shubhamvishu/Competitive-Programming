//https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        stack<int>s;
        vector<int>visited(n);
        vector<vector<int>>vec(n);
        map<pair<int,int>,int>umap;
        for(auto v:connections){
            vec[v[0]].push_back(v[1]);
            vec[v[1]].push_back(v[0]);
            umap[{v[0],v[1]}]=1;
        }
         s.push(0);
        int count=0;
        while(!s.empty()){
            int ele=s.top();
            visited[ele]=1;
            s.pop();
            for(int i:vec[ele]){
                if(!visited[i]){
                    s.push(i);
                    count+=umap[{ele,i}];
                }
            }
        }
        return count;
    }
};
