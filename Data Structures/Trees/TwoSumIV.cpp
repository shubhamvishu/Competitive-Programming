//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
public:
    unordered_map<int,int>m1;
    vector<int>v1;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(int i:v1)
            if(m1[k-i] && i!=k-i)
                return true;
        return false;
    }
    void inorder(TreeNode* root){
        if(root!=NULL) {
            v1.push_back(root->val);
            m1[root->val]=1;
        }
        if(root->left!=NULL) inorder(root->left);
        if(root->right!=NULL) inorder(root->right);
    }
};
