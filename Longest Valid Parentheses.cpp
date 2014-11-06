// use stack 难调试
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> a;
        bool b = false;
        int i, l = 0, maxl = 0;
        for(i = 0; i < s.length(); i++) {
            if(s[i] == '(') 
                a.push(0);
            else if(!a.empty() && a.top() >= 0){
                l = 0;
                b = false;
                while(!a.empty() && a.top() >= 0) {
                    if(a.top() == 0) {
                        if(b)
                            break;
                        else {
                            l += 2;
                            b = true;
                        }
                    }
                    l += a.top();
                    a.pop();
                }
                a.push(l);
                maxl = max(maxl, l);
                if(!b)
                    a.push(-1);
            }
            else
                a.push(-1);
        }
        return maxl;
    }
};
