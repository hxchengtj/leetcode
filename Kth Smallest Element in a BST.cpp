/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        int i = 0;
        while(p || !stk.empty()) {
            while(p) {
                stk.push(p);
                p = p->left;
            }
            TreeNode* t = stk.top();
            stk.pop();
            i++;
            if(i == k) return t->val;
            p = t->right;
        }
        return -1;
    }
};


//redo
int kthSmallestElement(TreeNode* root, int k) {
  TreeNode* p = root;
  stack<TreeNode*> stk;
  while(p || !stk.empty()) {
    while(p) {
      stk.push(p);
      p = p->left;
    }
    TreeNode* t = stk.top();
    stk.pop();
    if(--k == 0) return t->val;
    p = t->right;
  }
  return 0;
}

