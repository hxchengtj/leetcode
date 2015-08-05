class Solution {
public:
    int v;
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return 1;
        v = -1000000000;
        return ldr(root);
    }
    bool ldr(TreeNode *root) {
        if(root == NULL)
            return 1;
        if(!ldr(root->left))
            return 0;
        if(v >= root->val)
            return 0;
        v = root->val;
        return ldr(root->right);
    }
};


//version2
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* p = root;
        TreeNode* pre = NULL;
        stack<TreeNode*> stk;
        while(p || !stk.empty()) {
            while(p) {
                stk.push(p);
                p = p->left;
            }
            TreeNode* t = stk.top();
            if(pre && pre->val >= t->val) return false;
            stk.pop();
            pre = t;
            p = t->right;
        }
        return true;
    }
};

//version2
//redo
bool isValidBST(TreeNode* root) {
  TreeNode* p = root, *prev = NULL;
  stack<TreeNode*> stk;
  while(p || !stk.empty()) {
    while(p) {
      stk.push(p);
      p = p->left;
    }
    TreeNode* t = stk.top();
    stk.pop();
    if(prev && prev->val >= t->val) return false;
    prev = t;
    p = t->right;
  }
  return true;
}

