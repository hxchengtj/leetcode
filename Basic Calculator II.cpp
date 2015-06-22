class Solution {
public:
    void calnum(stack<int> &si, char c) {
        int a = si.top();
        si.pop();
        int b = si.top();
        si.pop();
        switch(c) {
            case '*': si.push(a*b); return;
            case '/': si.push(b/a); return;
            case '+': si.push(a+b); return;
            case '-': si.push(b-a); return;
        }
    }
    int getnum(string &s, int l, int & r) {
        int i;
        for(i = l;s[i] >= '0' && s[i] <= '9'; i++);
        int num = atoi(s.substr(l, i-l).c_str());
        r = i-1;
        return num;
    }
    int calculate(string s) {
        stack<int> si;
        stack<char> sc;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                int num = getnum(s, i, i);
                si.push(num);
            }
            else if(s[i] != ' ') {
                if(s[i] == '*' || s[i] == '/') {
                    int r, j = i+1;
                    while(s[j] == ' ')
                        j++;
                    int num = getnum(s, j, r);
                    si.push(num);
                    calnum(si, s[i]);
                    i = r;
                }
                else {
                    while(!sc.empty()) {
                        char c = sc.top();
                        calnum(si, c);
                        sc.pop();
                    }
                    sc.push(s[i]);
                }
            }   
        }
        while(!sc.empty()) {
            char c = sc.top();
            calnum(si, c);
            sc.pop();
        }
        return si.top();
    }
};