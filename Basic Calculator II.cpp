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

//redo
int calculate(string s) {
  stack<int> val;
  stack<char> cal;
  auto cmp = [](const char & a, const char & b) {
    if((a == '+' || a == '-') && (b == '*' || b == '/')) return true;
    return false;
  };
  int n = s.size(), i = 0;
  while(i <= n) {
    if(i == n || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      if(i == n || (!cal.empty() && !cmp(cal.top(), s[i]))) {
        char c = i == n ? '+':s[i];
        while(!cal.empty() && !cmp(cal.top(), c)) {
          int b = val.top();
          val.pop();
          switch(cal.top()) {
            case '+': val.top() += b; break;
            case '-': val.top() -= b; break;
            case '*': val.top() *= b; break;
            case '/': val.top() /= b;
          }
          cal.pop();
        }
      }
      if(i != n) cal.push(s[i]);
      i++;
    }
    else if(isdigit(s[i])) {
      int j = i;
      while(i < n && isdigit(s[i])) i++;
      int a = stoi(s.substr(j, i-j));
      val.push(a);
    }
    else i++;
  }
  return val.top();
}

