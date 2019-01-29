//https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
//Submitted-code(link below)
//https://www.hackerrank.com/challenges/tree-huffman-decoding/submissions/code/96682997

void decode_huff(node * root, string s) {
    for(int i=0;i<s.length();)
    {
        node *p=root;
        while(p->data==0 && p->freq>0)
        {
            p=(s[i]=='0')?p->left:p->right;
            i++;
        }
        cout<<p->data;(p->freq)--;
    }
}

