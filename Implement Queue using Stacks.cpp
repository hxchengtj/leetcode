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


//version2
class Queue {
public:
    stack<int> pushstk;
    stack<int> popstk;
    // Push element x to the back of queue.
    void push(int x) {
        pushstk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(popstk.empty()) {
            while(!pushstk.empty()) {
                popstk.push(pushstk.top());
                pushstk.pop();
            }
        }
        popstk.pop();
    }

    // Get the front element.
    int peek(void) {
        if(popstk.empty()) {
            while(!pushstk.empty()) {
                popstk.push(pushstk.top());
                pushstk.pop();
            }
        }
        return popstk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return pushstk.empty() && popstk.empty();
    }
};


//redo
class Queue {
  public:
    stack<int> pushstk;
    stack<int> popstk;

    void push(int x) {
      pushstk.push(x);
    }

    void pop(void) {
      if(popstk.empty()) {
        while(!pushstk.empty()) {
          popstk.push(pushstk.top());
          pushstk.pop();
        }
      }
      popstk.pop();
    }

    int peek(void) {
      if(popstk.empty()) {
        while(!pushstk.empty()) {
          popstk.push(pushstk.top());
          pushstk.pop();
        }
      }
      return popstk.top();
    }

    bool empty(void) {
      return pushstk.empty() && popstk.empty();
    }
};

