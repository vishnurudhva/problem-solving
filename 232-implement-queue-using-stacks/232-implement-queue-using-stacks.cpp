class MyQueue {
public:
    stack<int> s1, s2;
    int size = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int getTop() {
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    void flushStack() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        if (!s2.empty()) return getTop();
        
        flushStack();
        
        return getTop();
    }
    
    int peek() {
        if (!s2.empty()) return s2.top();
        
        flushStack();
        
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */