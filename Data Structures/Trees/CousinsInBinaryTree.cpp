//https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        map<int,pair<int,int>>m1;
        func(root,x,y,m1,-1,0);
        return (m1[x].first!=m1[y].first && m1[x].second==m1[y].second);
    }
    void func(TreeNode* root,int x,int y,map<int,pair<int,int>>&m1,int p,int d){
        m1[root->val]={p,d};
        if(root->left) func(root->left,x,y,m1,root->val,d+1);
        if(root->right) func(root->right,x,y,m1,root->val,d+1);
    }
};
