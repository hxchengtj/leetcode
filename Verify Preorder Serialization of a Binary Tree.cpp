class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i = 0, j, n = preorder.size();
        vector<int> v;
        for(j = 0; j <= n; j++) {
            if (j == n || preorder[j] == ',') {
                if(preorder.substr(i, j-i) == "#") v.push_back(0);
                else v.push_back(1);
                i = j+1;
            }
        }
        stack<bool> stk;
        for(i = 0; i < v.size(); i++) {
            if(v[i] == 0) {
                while(!stk.empty() && stk.top()) stk.pop();
                if(stk.empty() && i < v.size()-1) return false;
                if(!stk.empty()) stk.top() = true;
            } else stk.push(false);
        }
        return stk.empty();
    }
};
