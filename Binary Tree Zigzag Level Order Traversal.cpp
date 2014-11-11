class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode *> s1, s2;
        vector<int> v;
        vector<vector<int> > ans;
        s1.push(root);
        while(!s1.empty() || !s2.empty()) {
            while(!s1.empty()) {
                if(s1.top() != NULL) {
                    v.push_back(s1.top()->val);
                    s2.push(s1.top()->left);
                    s2.push(s1.top()->right);
                }
                s1.pop();
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
            while(!s2.empty()) {
                if(s2.top() != NULL) {
                    v.push_back(s2.top()->val);
                    s1.push(s2.top()->right);
                    s1.push(s2.top()->left);
                }
                s2.pop();
            }
            if(v.size())
                ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};