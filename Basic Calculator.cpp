class Solution {
public:
    void cal_num(stack<int> & si, char cal)
    {
        int a = si.top();
        si.pop();
        int b = si.top();
        si.pop();
        if(cal == '+')
            si.push(a + b);
        else if(cal == '-')
            si.push(b-a); 
        
    }
    int calculate(string s) {
        stack<char> sc;
        stack<int> si;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] <= '9' && s[i] >= '0')
            {
                int num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                si.push(num);
                i--;
                continue;
            }
            if(s[i] == ')')
            {
                while(!sc.empty() && sc.top() != '(')
                {
                    cal_num(si, sc.top());
                    sc.pop();
                }
                sc.pop();
            }
            else if (s[i] == '(')
                sc.push(s[i]);
            else if(s[i] != ' ')
            {  
                while(!sc.empty() && sc.top() != '(')
                {
                    cal_num(si, sc.top());
                    sc.pop();
                }
                sc.push(s[i]);
            }
        }
        while(!sc.empty() && sc.top() != '(')
        {
            cal_num(si, sc.top());
            sc.pop();
        }        
        return si.top();
    }
};

//redo
class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        stack<char> ops;
        int b = 0, e = 0;
        while(b <= s.size()) {
            if(b == s.size() || s[b] == '+' || s[b] == '-' || s[b] == ')') {
                while(!ops.empty()) {
                    if(ops.top() == '(') {
                        if(b < s.size() && s[b] == ')') ops.pop();
                        break;
                    }
                    int a = vals.top();
                    vals.pop();
                    switch(ops.top()) {
                        case '+': vals.top() += a; break;
                        case '-': vals.top() -= a; break;
                    }
                    ops.pop();
                       
                }
                if(b < s.size() && (s[b] == '+' || s[b] == '-'))  ops.push(s[b]);
                b++;
            }
            else if(s[b] == '(')
                ops.push(s[b++]);
            else if(isdigit(s[b])) {
                e = b+1;
                while(e < s.size() && isdigit(s[e])) e++;
                int v = stoi(s.substr(b, e-b));
                vals.push(v);
                b = e;
            }
            else b++;
        }
        return vals.top();
    }
};