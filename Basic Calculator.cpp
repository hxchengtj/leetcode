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