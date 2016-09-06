/* review again */
// hard
// 要扫描两次，正序扫描可能出现最终sum > 0的情况，即'('更多；逆序扫描可能出现最终sum < 0的情况，')'未完全匹配，两者结合可获得全部解
class Solution {
public:
    int longestValidParentheses(string s) {
        int i;
        int j = 0, maxl = 0, sum = 0;
        for(i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                sum += 1;
            else
                sum += -1;
            if(sum == 0)
                maxl = max(maxl, i - j + 1);
            else if(sum < 0) {
                sum = 0;
                j = i+1;
            }
        }
        sum = 0;
        j = s.length()-1;
        for(i = s.length()-1; i >= 0; i--) {
            if(s[i] == '(')
                sum += 1;
            else
                sum += -1;
            if(sum == 0)
                maxl = max(maxl, j - i + 1);
            else if(sum > 0) {
                sum = 0;
                j = i-1;
            }
        }
        return maxl;
    }
};

//version2
int longestValidParentheses(string s) {
  stack<int> stk;
  int j = 0, ans = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(') stk.push(i);
    else if(stk.empty()) j = i+1;
    else {
      stk.pop();
      int k = stk.empty()? j:stk.top()+1;
      ans = max(ans, i-k+1);
    }
  }
  return ans;
}

