/* review again */
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

//version2
//recursive
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ln = 0, rn = 0;
        TreeNode* l = root, *r = root;
        while(l) {
            ln++; l = l->left;
        }
        while(r) {
            rn++; r = r->right;
        }
        //使用位运算 而不是pow, 速度会变快, 同时记得加括号,注意运算符优先级
        if(ln == rn) return (1 << ln)-1;
        // 切分后至少有一个会满足ln == rn
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

//iterative
class Solution {
public:
    int height(TreeNode* root) {
        int n = -1;
        while(root) {
            n++; root = root->left;
        }
        return n;
    }
    int countNodes(TreeNode* root) {
        int h = height(root), ans = 0;
        while(root) {
            if(height(root->right) == h-1) {
                ans += (1 << h);
                root = root->right;
            } else {
                ans += (1 << (h-1));
                root = root->left;
            }
            h--;
        }
        return ans;
    }
};

