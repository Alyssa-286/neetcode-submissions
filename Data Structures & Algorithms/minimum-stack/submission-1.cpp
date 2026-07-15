class MinStack {
    private:
    stack<int>vs,ms;

public:
    MinStack() {
    }
    
    void push(int val) {
        vs.push(val);
        if(ms.empty())
        ms.push(val);
        else
        ms.push(min(val,ms.top()));
        
    }
    
    void pop() {
        vs.pop();
        ms.pop();
        
    }
    
    int top() {
        return vs.top();
       
        
    }
    
    int getMin() {
        return ms.top();
        
    }
};
