class Queue {
public:
    stack<int> stk;
    // Push element x to the back of queue.
    void push(int x) {
        stk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while(!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        tmp.pop();
        while(!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int ret;
        stack<int> tmp;
        while(!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        ret = tmp.top();
        while(!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }        
        return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};