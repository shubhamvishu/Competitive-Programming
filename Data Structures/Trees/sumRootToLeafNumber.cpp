//https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*,int>>s1;
        s1.push({root,root->val});
        int sum=0;
        while(!s1.empty()){
            auto x=s1.top();
            //cout<<x.first->val;
            s1.pop();
            if(x.first->left==NULL && x.first->right==NULL)
                sum+=x.second;
            else{
                if(x.first->left){
                    s1.push({x.first->left,x.second*10+x.first->left->val});
                }
                if(x.first->right){
                    s1.push({x.first->right,x.second*10+x.first->right->val});
                }
            }
        }
        return sum;
    }
};
