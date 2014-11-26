class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                a.push(s[i]);
            else {
                if(a.empty())
                    return false;
                switch(s[i]) {
                    case ')': if(a.top() != '(') return false; a.pop(); break;
                    case '}': if(a.top() != '{') return false; a.pop(); break;
                    case ']': if(a.top() != '[') return false; a.pop(); 
                }
            }
        }
        if(a.empty())
            return true;
        return false;
    }
};
