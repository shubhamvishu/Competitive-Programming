//https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int result=0;

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        Dia(root);
        return result;
    }
     int Dia(TreeNode* root){
        int l=0,r=0,max=0;
        if(root->left!=NULL)
            l=Dia(root->left);
        if(root->right!=NULL)
            r=Dia(root->right);
        if((l+r)>result) result=(l+r);
        max=(l>r)?l:r;
        return max+1;
        }
};
