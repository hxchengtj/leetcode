// 之前貌似讲过这个题 好像能不断优化还是怎样? 忘记了> <
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
    int get_height(TreeNode* root) {
        int h = 0;
        while(root != NULL) {
            root = root->left;
            h++;
        }
        return h;
    }
    int get_right_h(TreeNode* root) {
        int h = 0;
        while(root != NULL) {
            root = root->right;
            h++;
        }
        return h;
    }
    int get_num(TreeNode * root, int h) {
        if(root == NULL) return 0;
        if(h == 1) return 1;

        int rh = get_right_h(root->left);
        if (rh == h-1)
            return (1 << (rh-1)) + get_num(root->right, h-1);
        else
            return get_num(root->left, h-1);
    }

    int countNodes(TreeNode* root) {
        int h = get_height(root);
        if(h == 0)
            return 0;
        if(h == 1)
            return 1;

        return (1 << (h-1)) - 1 + get_num(root, h);
    }
};

//redo
int get_left_height(TreeNode* root) {
  int h = 0;
  for(TreeNode* p = root; p; p = p->left) h++;
  return h;
}
int get_right_height(TreeNode* root) {
  int h = 0;
  for(TreeNode* p = root; p; p = p->right) h++;
  return h;
}
int __countNodes(TreeNode* root, int h) {
  int lh = get_left_height(root);
  if(lh < h) return 0;
  if(h == 1) return 1;
  int rh = get_right_height(root->left);
  if(rh == h-1) return (1 << (rh-1)) + __countNodes(root->right, h-1);
  else return __countNodes(root->left, h-1);
}
int countNodes(TreeNode* root) {
  if(root == NULL) return 0;
  int h = get_left_height(root);
  return (1 << (h-1)) -1 + __countNodes(root, h);
}

