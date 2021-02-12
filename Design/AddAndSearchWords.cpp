//https://leetcode.com/problems/design-add-and-search-words-data-structure/

class Node{
    public:
    char ch;
    bool isend;
    Node* arr[26];
    Node(char c){
        ch=c;
        isend=false;
        memset(arr,NULL,sizeof(arr));
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *head;
    WordDictionary() {
        head=new Node(' ');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *temp=head;
        for(char c:word){
            int x=c-'a';
            if(temp->arr[x]==NULL)
                temp->arr[x]=new Node(c);
            temp=temp->arr[x];
        }
        temp->isend=true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node *t=head;
        return searchword(word,t,0);
    }
    bool searchword(string word,Node* node,int index){
        bool b=false;
        if(index==word.length()) {return node->isend;}
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(node->arr[i]!=NULL)
                    b|=searchword(word,node->arr[i],index+1);
            }
        }
        else{
            if(node->arr[word[index]-'a']!=NULL)
                b|=searchword(word,node->arr[word[index]-'a'],index+1);
        }
        return b;
    }
};
