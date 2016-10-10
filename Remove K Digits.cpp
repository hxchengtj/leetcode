/* review again */
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n <= k) return "0";
        stack<char> stk;
        for(int i = 0; i < n; i++) {
            while(k > 0 && !stk.empty() && stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(--k >= 0)
            stk.pop();
        string s;
        while(!stk.empty()) {
            s.push_back(stk.top());
            stk.pop();
        }
        while(!s.empty() && s.back() == '0') s.pop_back();
        if(s.empty()) s = "0";
        reverse(s.begin(), s.end());
        return s;
    }
};
