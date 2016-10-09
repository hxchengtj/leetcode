class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> stk;
        int i = 0, n = s.size();
        stk.push({1, ""});
        while(i < n) {
            if(isdigit(s[i])) {
                int j = i;
                while(i < n && isdigit(s[i])) i++;
                stk.push({stoi(s.substr(j, i-j)), ""});
                if(i < n && s[i] == '[') i++;
            } else if(s[i] == ']') {
                auto t = stk.top();
                stk.pop();
                for(int j = 0; j < t.first; j++)
                    stk.top().second.append(t.second);
                i++;
            } else {
                stk.top().second.push_back(s[i++]);
            }
        }
        return stk.top().second;
    }
};
