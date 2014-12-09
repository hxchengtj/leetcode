class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return *dfs(1, n);
    }
   vector<TreeNode *> *dfs(int l, int r) {
        vector<TreeNode *> *v = new vector<TreeNode *>;
        if(l > r) {
            (*v).push_back(NULL);
            return v;
        }
        vector<TreeNode *> *lv, *rv;
        for(int i = l; i <= r; i++) {
            lv = dfs(l, i-1);
            rv = dfs(i+1, r);
            for(int j = 0; j < lv->size(); j++)
                for(int k = 0; k < rv->size(); k++) {
                    TreeNode *t = new TreeNode(i);
                    t->left = (*lv)[j];
                    t->right = (*rv)[k];
                    (*v).push_back(t);
                }
        }
        return v;
        
    }
};