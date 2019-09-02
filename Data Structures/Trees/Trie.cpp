//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

#include<bits/stdc++.h>
using namespace std;
#define f(a,j,k) for(int i=a;i<j;i+=k)
class Node{
    public:
    Node(long p):weight(p){}
    Node * nextchar[26];
    long weight;
};
long maxx=0;
string match="";
void findmatches(Node * temp)
{
    if(temp->weight>maxx)
    {
        maxx=temp->weight;
    }
    f(0,26,1)
    {
        if(temp->nextchar[i]!=NULL)
        {
            findmatches(temp->nextchar[i]);
        }
    }
}
int main()
{
    long n,q,p;
    string s;
    scanf("%ld %ld",&n,&q);
    Node * newnode=new Node(-1);
    Node * temp=newnode;
    f(0,n,1)
    {
        temp=newnode;
        cin>>s>>p;
        for(char ch:s)
        {
            if(temp->nextchar[ch-'a']==NULL)
            temp->nextchar[ch-'a']=new Node(-1);
            temp=temp->nextchar[ch-'a'];
        }
        temp->weight=p;
    }
    unordered_map<string,long>m1;
    f(0,q,1)
    {
        temp=newnode;
        cin>>s;
        if(m1[s])
        cout<<m1[s]<<endl;
        else{
        int f=0;
        for(char ch:s)
        {
          if(temp->nextchar[ch-'a']!=NULL)
            {
              temp=temp->nextchar[ch-'a'];
            }          
          else{
              f=1;
              break;
              }
        }
        if(f) cout<<"-1"<<endl;
        else{
            findmatches(temp);
            cout<<maxx<<endl;
            m1[s]=maxx;
            maxx=0;
             }
      }
    }    
}