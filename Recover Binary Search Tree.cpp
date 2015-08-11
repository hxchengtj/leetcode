class Solution {
public:
    int a = INT_MIN;
    TreeNode *l = NULL, *r = NULL, *p = NULL;
    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(l->val, r->val);
    }
    void dfs(TreeNode *root) {
        if(root == NULL)
            return;
        dfs(root->left);
        if(a > root->val) {
            if(l == NULL)
                l = p;
            r = root;
        }
        a = root->val;
        p = root;
        dfs(root->right);
    }
};

//redo
void recoverTree(TreeNode* root) {
  TreeNode* p = root, * pre = NULL, *a = NULL, *b = NULL;
  stack<TreeNode*> stk;
  while(p || !stk.empty()) {
    while(p) {
      stk.push(p);
      p = p->left;
    }
    TreeNode* t = stk.top();
    stk.pop();
    if(pre != NULL && pre->val > t->val) {
      if(a == NULL) a = pre;
      b = t;
    }
    pre = t;
    p = t->right;
  }
  swap(a->val, b->val);
}

