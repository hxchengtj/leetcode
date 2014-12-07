class MinStack {
public:
    stack<int> s;
    stack<int> q;
    void push(int x) {
        s.push(x);
        if(q.empty() || q.top() >= x)
            q.push(x);
    }

    void pop() {
        if(s.top() == q.top())
            q.pop();
        s.pop();
    }

    int top() {
        return s.top();   
    }

    int getMin() {
        return q.top();
    }
};