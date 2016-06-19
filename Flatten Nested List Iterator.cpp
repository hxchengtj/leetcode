// review
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger> stk;
    int element;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(nestedList.size() == 0) return;
        for(int i = nestedList.size()-1; i >= 0; i--) stk.push(nestedList[i]);
    }

    int next() {
        return element;
    }

    bool hasNext() {
        while (!stk.empty() && !stk.top().isInteger()) {
            auto a = stk.top();
            stk.pop();
            auto v = a.getList();
            for(int i = v.size()-1; i >= 0; i--) stk.push(v[i]);
        }
        if (!stk.empty()) {
            element = stk.top().getInteger();
            stk.pop();
            return true;
        } else return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
