// get min in o(1) extra time ans o(1) extra space 
class MinStack {
private:
    stack<long long> s;
    long long cur_min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        if(s.size()==0)
        {
            cur_min=val;
            s.push(val);
            return;
        }
        if(val<cur_min)
        {
            s.push(2ll*val-cur_min);     //  val---
            cur_min=val;
        }
        else
        {
            s.push(val);
        }
    }
    
    void pop() {
        if(s.top()<cur_min)
        {
            cur_min=2*cur_min-s.top();
        }
        s.pop();
    }
    
    int top() {
        return (cur_min>s.top())?cur_min:s.top();
    }
    
    int getMin() {
        return cur_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */