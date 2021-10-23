//https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,pair<int,int>>mp;
        vector<int>result(nums1.size(),-1);
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]] = {true, i};
        }
        stack<int>st;
        st.push(-1);
        int index = 0;
        while(!st.empty() && index < nums2.size()){
            int top = st.top();
            while(!st.empty() && st.top() < nums2[index]){
                    if(mp[st.top()].first){
                        result[mp[st.top()].second] = nums2[index];
                    }
                st.pop();
            }
            st.push(nums2[index++]);
        }
        return result;
    }
};
