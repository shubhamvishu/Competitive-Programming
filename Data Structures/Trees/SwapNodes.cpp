//https://www.hackerrank.com/challenges/swap-nodes-algo/problem

#include <bits/stdc++.h>
using namespace std;

vector<int>vec;

 class Node{

 public:
   static int maxH;
   Node *left;
   Node *right;
   int data, height;
   Node(int d, int h) {
     left=NULL;
     right=NULL;
     data = d;
     height = h;
     if(h>maxH)maxH=h;
     }
     Node(){}
 };

 int Node::maxH=0;

 void inorder(Node *head){
     if(head->left!=NULL)
      inorder(head->left);
      cout<<head->data<<" ";vec.push_back(head->data);
     if(head->right!=NULL)
      inorder(head->right);
     return;

 }
 vector<vector<int>> swapNodes(vector<vector<int>> indexes,
                               vector<int> queries) {

   vector<vector<int>>result;
   Node *head = new Node(1, 1);
   queue<Node *> q1;
   vector<Node *>v1;
   q1.push(head);
   v1.push_back(head);
   int h1 = 1, in = 1;
   for (int i = 0; i < indexes.size() && q1.size() != 0; i++) 
   {
     Node *curr = q1.front();
     if (indexes[i][0] != -1) {
       in++;
       Node *newNode = new Node(in, curr->height + 1);
       curr->left = newNode;
       q1.push(curr->left);
       v1.push_back(curr->left);
     }
     if (indexes[i][1] != -1) {
       in++;
       Node *newNode = new Node(in, curr->height + 1);
       curr->right = newNode;
       q1.push(curr->right);
       v1.push_back(curr->right);
     }
     q1.pop();
   }
   //inorder(head);cout<<endl;
   for (int i = 0; i < queries.size(); i++)
   {
     for(int j=0;j<v1.size();j++)
     {
         if(v1[j]->height%queries[i]==0)
         {
           Node *temp = v1[j]->left;
           v1[j]->left = v1[j]->right;
           v1[j]->right = temp;
         }
     }
     inorder(head);
     result.push_back(vec);
     vec.clear();
   }
   return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);
    swapNodes(indexes,queries);
   for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

