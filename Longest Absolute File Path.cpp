class Solution {
public:
    int lengthLongestPath(string input) {
        stack<pair<int, int>> stk;
        int ans = 0;
        int i = 0, j = 0, n = input.size();
        while(i < n) {
            if(input[i] == '\n') i++;
            int k = 0;
            while(i < n && input[i] == '\t') {
                k++;
                i++;
            }
            while(!stk.empty() && stk.top().second >= k) stk.pop();
            j = i;
            bool isFile = false;
            while(i < n && input[i] != '\n') {
                if(input[i] == '.') isFile = true;
                i++;
            }
            if(isFile) ans = max(ans, (stk.empty()?0:stk.top().first)+i-j);
            else if(j < i) {
                stk.push(make_pair((stk.empty()?0:stk.top().first)+i-j+1, k));
            }
        }
        return ans;
    }
};
