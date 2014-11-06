class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        
        int i, a, b, ans;
        for(i = 0; i < tokens.size(); i++) {
            if(tokens[i][tokens[i].size()-1] >= '0' && tokens[i][tokens[i].size()-1] <= '9')    //需要考虑负数的情况
                s.push(tokens[i]);
            else {
                b = atoi(s.top().c_str());  //注意a,b顺序
                s.pop();
                a = atoi(s.top().c_str());
                s.pop();
                if(tokens[i][0] == '+')
                    ans = a + b;
                else if(tokens[i][0] == '-')
                    ans = a - b;
                else if(tokens[i][0] == '*')
                    ans = a * b;
                else 
                    ans = a / b;
                char c[100];
                sprintf(c, "%d", ans);
                string ss(c);
                s.push(ss);
            }
        }
        return atoi(s.top().c_str());
    }
};
