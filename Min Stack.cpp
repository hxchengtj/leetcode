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


//redo
class MinStack {
  stack<int> stk;
  stack<int> minstk;
  public:
  void push(int x) {
    if(minstk.empty() || minstk.top() >= x) minstk.push(x);
    stk.push(x);
  }

  void pop() {
    if(minstk.top() == stk.top()) minstk.pop();
    stk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return minstk.top();
  }
};

