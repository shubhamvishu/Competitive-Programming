//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,multiset<string>>m1;
        string temp;
        for(string str:strs){
            temp=str;
            sort(temp.begin(),temp.end());
            m1[temp].insert(str);
        }

        vector<vector<string>>v1;
        for(auto it=m1.begin();it!=m1.end();it++){
            vector<string>v2;
            multiset<string>::iterator j=(it->second).begin();
            for(j=(it->second).begin();j!=(it->second).end();j++){
                v2.push_back(*j);
            }
            v1.push_back(v2);
        }
        return v1;
    }
};