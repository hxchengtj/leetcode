//redo 
class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    if(preorder.empty()) return true;
    stack<int> stk;
    int low = -1;
    for(int i = 0; i < preorder.size(); i++) {
      if(low >= 0 && preorder[i] <= preorder[low]) return false;
      while(!stk.empty() && preorder[stk.top()] < preorder[i]) {
        low = stk.top();
        stk.pop();
      }
      if(!stk.empty() && preorder[stk.top()] == preorder[i]) return false;
      stk.push(i);
    }
    return true;
  }
};
