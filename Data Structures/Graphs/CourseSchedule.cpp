//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(!prerequisites.size()) return true;
        vector<vector<int>>vec(numCourses);
        for(auto p:prerequisites)
            vec[p[0]].push_back(p[1]);
        stack<int>s;
        for(int i=0;i<numCourses;i++)
            if(!vec[i].size()) s.push(i);
        if(s.empty()) return false;
        int x=0;
        while(!s.empty()){
            int ele=s.top();
            s.pop();
            for(int i=0;i<numCourses;i++){
                auto it=find(vec[i].begin(),vec[i].end(),ele);
                if(it!=vec[i].end()) {
                    vec[i].erase(it);
                    if(!vec[i].size()) s.push(i);
                }
            }
            x++;
        }
        return x==numCourses;
    }
};
