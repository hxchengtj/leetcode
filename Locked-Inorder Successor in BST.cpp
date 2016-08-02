class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* t = NULL;
    while(root) {
      if(root->val <= p->val ) root = root->right;
      else {
        t = root;
        root = root->left;
      }
    }
    return t;
  }
};
