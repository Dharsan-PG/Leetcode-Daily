class MyStack {
public:
    queue<int> q;
    int topelement;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
        topelement = x;
    }
    
    int pop() {
        int sz = q.size();
        while(sz>1) {
            this->push(q.front());
            q.pop();
            sz--;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return this->topelement;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */