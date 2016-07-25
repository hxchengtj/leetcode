class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *root) {
    TreeNode* leftNode = root, *parent = NULL, * right = NULL;
    while(leftNode) {
      TreeNode* l = leftNode->left, *r = leftNode->right;
      leftNode->left = right;
      leftNode->right = parent;
      parent = leftNode;
      right = r;
      leftNode = l;
    }
    return parent;
  }
};
