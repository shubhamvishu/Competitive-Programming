//https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    bool prune(TreeNode* root){
        if(root==NULL) return false;

        bool b1 = prune(root->left);
        if(!b1) root->left=NULL;

        bool b2 = prune(root->right);
        if(!b2) root->right=NULL;

        return b1 || b2 || (root->val==1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* temp = root;
        return prune(root)?root:NULL;  
    }
};
