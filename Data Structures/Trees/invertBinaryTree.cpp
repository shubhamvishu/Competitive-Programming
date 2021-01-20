//https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode *x=s.top();
            s.pop();
            TreeNode *temp=x->left;
            x->left=x->right;
            x->right=temp;
            if(x->left) s.push(x->left);
            if(x->right) s.push(x->right);
        }
        return root;
    }
};
