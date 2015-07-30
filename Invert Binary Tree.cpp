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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode* right = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(right);
        return root;
    }
};

//version2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

//redo
TreeNode* invertTree(TreeNode* root) {
  if(root == NULL) return NULL;
  TreeNode *left = invertTree(root->left);
  TreeNode * right = invertTree(root->right);
  root->left = right;
  root->right = left;
  return root;
}

