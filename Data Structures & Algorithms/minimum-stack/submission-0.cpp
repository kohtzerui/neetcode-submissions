class MinStack {
private:
    stack<int> working = {};
    stack<int> min_tracker = {};
public:   
    MinStack(){

    }

    void push(int val) {
        working.push(val);
        
        if(min_tracker.empty() || val < min_tracker.top()){
            min_tracker.push(val);
        } else {
            if(val >= min_tracker.top()){
                min_tracker.push(min_tracker.top());
            }
        }
    }
    
    void pop() {
        working.pop();
        min_tracker.pop();
    }
    
    int top() {
        return working.top();
    }
    
    int getMin() {
        return min_tracker.top();
    }
};
