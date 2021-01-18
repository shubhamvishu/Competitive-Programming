//https://leetcode.com/problems/lru-cache/

struct ListNod{
    pair<int,int>data;
    ListNod* next;
    ListNod* prev;
    ListNod(int key,int value){
        data.first=key;
        data.second=value;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    int size=0,C;
    ListNod* head,*end;
    unordered_map<int,ListNod*>m1;
    LRUCache(int capacity) {
         this->C=capacity;
    }

    int get(int key) {
        if(m1[key]){
            ListNod* ele=m1[key];
            cacheHit(ele);
            return m1[key]->data.second;
        }
        return -1;
    }

    void put(int key, int value) {

        if(m1[key]){
            //cout<<"M"<<endl;
            ListNod* ele=m1[key];
            ele->data.second=value;
            cacheHit(ele);
        }
        else{
            if(size==0){
                head=new ListNod(key,value);
                end=head;
                head->prev=NULL;
                head->next=NULL;
                m1[key]=head;
                ++size;
            }
            else if(size<C){
                addToCache(key,value);
                ++size;
            }
            else{
                removeFirst();
                addToCache(key,value);
            }

        }
    }
    void removeFirst(){
        if(head->next)
        head->next->prev=NULL;
        m1[head->data.first]=NULL;
        head=head->next;
    }
    void removeMid(ListNod* ele){
        if(ele->prev)
            ele->prev->next=ele->next;
        if(ele->next)
            ele->next->prev=ele->prev;
        ele->next=NULL;
    }
    void addToCache(int key,int value){
        ListNod* ele=new ListNod(key,value);
        end->next=ele;
        ele->prev=end;
        end=end->next;
        m1[key]=ele;
    }
    void cacheHit(ListNod* ele){
        if(ele!=end && ele==head) {
            removeFirst();
            addToCache(ele->data.first,ele->data.second);
        }
        else if(ele!=end){
            removeMid(ele);
            addToCache(ele->data.first,ele->data.second);
        }
    }

};
