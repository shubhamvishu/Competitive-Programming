//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    map<int,vector<pair<int,int>>>umap;
    int minn=INT_MAX;
    void bfs(TreeNode* root,int x){
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            //cout<<"yo";
            q.pop();
            if(p.second.first<minn) minn=p.second.first;
            //cout<<p.second<<" "<<p.first->val<<endl;
            umap[p.second.first].push_back({p.first->val,p.second.second});
            if(p.first->left) q.push({p.first->left,{p.second.first-1,p.second.second-1}});
            if(p.first->right) q.push({p.first->right,{p.second.first+1,p.second.second-1}});
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root!=NULL)
            bfs(root,0);
        vector<vector<int>>res;
        for(int i=minn;umap[i].size()>0;i++){
            vector<pair<int,int>>temp;
            for(int j=0;j<umap[i].size();j++){
                temp.push_back(umap[i][j]);
            }
            auto f=[](auto& a,auto& b){
                if(a.second!=b.second) return a.second>b.second;
                return a.first<b.first;
            };
            sort(temp.begin(),temp.end(),f);
            vector<int>ans;
            for(auto x:temp)
                ans.push_back(x.first);
            res.push_back(ans);
        }
        return res;
    }
};
