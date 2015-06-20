class Stack {
public:
    queue<int> q;
    int topnum;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        topnum = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = q.size();
        for(int i = 0; i < size-1; i++)
        {
            int num = q.front();
            topnum = num;
            q.pop();
            q.push(num);
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        return topnum;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};