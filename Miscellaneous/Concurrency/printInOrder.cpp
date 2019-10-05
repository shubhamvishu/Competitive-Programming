class Foo {
public:
    bool b[3]={false,false,false};
    int i=0;
    Foo() {
    
    }

    void first(function<void()> printFirst) {
        
        while(i==1);
        i++;
        printFirst();
        b[0]=true;
        i--;
        
    }

    void second(function<void()> printSecond) {
        
        while(i==1 || b[0]==false);
        i++;
        printSecond();
        b[1]=true;
        i--;
        
    }

    void third(function<void()> printThird) {
        
        while(i==1 || b[0]==false || b[1]==false);
        i++;
        printThird();
        b[2]=true;
        i--;
    }
};