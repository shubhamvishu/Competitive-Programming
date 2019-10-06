class FooBar {
private:
    int n,b;
    std::mutex m;
    std::condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        this->b=0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std:unique_lock<std::mutex>lock(m);
            while(b)
            {
                cv.wait(lock);
            }
        	 printFoo();
             b=1;
             lock.unlock();
             cv.notify_one();
              
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
             std:unique_lock<std::mutex>lock(m);
            while(!b)
            {
                cv.wait(lock);
            }
        	 printBar();
             b=0;
             lock.unlock();
             cv.notify_one();
              
            
        	
        }
    }
};