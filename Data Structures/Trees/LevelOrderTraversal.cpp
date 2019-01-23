//https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
//Submitted-code(link below)
//https://www.hackerrank.com/challenges/tree-level-order-traversal/submissions/code/96590551


#include <bits/stdc++.h>

using namespace std;
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
   //My code for level order traversal
   void levelOrder(Node * root) {

        vector<Node *>v1;
        int f=0,r=-1;
        v1.push_back(root);
        r++;

        while(f<=r)
        {   
           Node * p=v1[f];

            if(p->left!=NULL)
            {v1.push_back(p->left); r++;}
	    if(p->right!=NULL)
	    {v1.push_back(p->right); r++;}

          f++;     
        }
        for(int i=0;i<v1.size();i++)
            cout<<v1[i]->data<<" ";

    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.levelOrder(root);

    return 0;
}

