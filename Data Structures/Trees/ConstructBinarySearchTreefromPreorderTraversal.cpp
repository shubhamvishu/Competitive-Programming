//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        stack<pair<TreeNode*,pair<int,int>>>s;
        int i=0;
        TreeNode* node=new TreeNode(preorder[i++]);
        s.push({node,{INT_MIN,INT_MAX}});
        while(!s.empty()){
            auto p=s.top();
            if(i<preorder.size() && preorder[i]<p.first->val && p.second.first<=preorder[i]){

                TreeNode *t=new TreeNode(preorder[i++]);
                p.first->left=t;
                s.push({t,{p.second.first,p.first->val-1}});
            }
            else if(i<preorder.size() && preorder[i]>p.first->val && p.second.second>=preorder[i]){

                TreeNode *t=new TreeNode(preorder[i++]);
                p.first->right=t;
                s.push({t,{p.first->val+1,p.second.second}});
            }
            else{
                s.pop();
            }
        }
        return node;
    }
};
