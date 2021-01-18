//https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    list<int>mystack;
    list<int>minn;
    int minval;
    MinStack() {
        minval=INT_MAX;
    }

    void push(int x) {
        if(x<=minval) {minn.push_back(x);minval=x;}
        else minn.push_back(minval);
        mystack.push_back(x);
    }

    void pop() {
        mystack.pop_back();
        minn.pop_back();
        minval=minn.back();
        if(minn.size()==0) minval=INT_MAX;
    }

    int top() {
        return mystack.back();
    }

    int getMin() {
        return minval;
    }
};
