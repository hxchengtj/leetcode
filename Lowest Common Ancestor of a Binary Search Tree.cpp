class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *t = root, *lp, *lq;
        while(t) {
            lp = t;
            if(t->val < p->val) lp = t->right;
            else if(t->val > p->val) lp = t->left;
            lq = t;
            if(t->val < q->val) lq = t->right;
            else if(t->val > q->val) lq = t->left;
            if(lp != lq) return t;
            t = lp;
        }
        return NULL;
    }
};

//redo
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* t = root;
  while(t) {
    if(t->val >= p->val && t->val <= q->val || t->val <= p->val && t->val >= q->val) break;
    else if(t->val > p->val) t = t->left;
    else t = t->right;
  }
  return t;
}

