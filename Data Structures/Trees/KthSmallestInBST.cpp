//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        s.push(root);
        int i=1;
        while(root!=NULL || !s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode* ele=s.top();
                s.pop();
                //cout<<ele->val<<endl;
                if(k==i++)
                    return ele->val;
                root=ele->right;
            }
        }
        return -1;
    }
};
