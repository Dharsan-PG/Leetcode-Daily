class MyQueue {
public:
    stack<int> st, s;
    int front = 0;
    MyQueue() {}

    void push(int x) {
        if (st.empty())
            front = x;
        st.push(x);
    }

    int pop() {
        if (s.empty()) {
            while (!st.empty()) {
                int x = st.top();
                st.pop();
                s.push(x);
            }
        }
        int y = s.top();
        s.pop();
        return y;
    }

    int peek() {
        if (!s.empty())
            return s.top();
        return front;
    }

    bool empty() { return st.empty() && s.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */