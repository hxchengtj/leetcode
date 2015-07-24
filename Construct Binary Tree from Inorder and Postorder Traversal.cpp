class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return dfs(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode *dfs(vector<int> &inorder, int b1, int e1, vector<int> &postorder, int b2, int e2) {
        if(e1-b1 < 0)
            return NULL;
        TreeNode *t = new TreeNode(postorder[e2]);
        for(int i = b1; i <= e1; i++) {
            if(inorder[i] == postorder[e2]) {
                t->left = dfs(inorder, b1, i-1, postorder, b2, b2+i-1-b1);
                t->right = dfs(inorder, i+1, e1, postorder, b2+i-b1, e2-1);
                break;
            }
        }
        return t;
    }
};
};

//version2
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
    TreeNode* __buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &m, int ib, int pb, int n) {
        if(n == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[pb+n-1]);
        int i = m[root->val];
        root->left = __buildTree(inorder, postorder, m, ib, pb, i-ib);
        root->right = __buildTree(inorder, postorder, m, i+1, pb+i-ib, n-i+ib-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        int n = inorder.size();
        for(int i = 0;i < inorder.size(); i++)
            m[inorder[i]] = i;
        return __buildTree(inorder, postorder, m, 0, 0, n);
    }
};

//version2
//redo
TreeNode* __buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& m, int bi, int bp, int n) {
  if(n <= 0) return NULL;
  int val = postorder[bp+n-1];
  TreeNode* t = new TreeNode(val);
  int k = m[val];
  t->left = __buildTree(inorder, postorder, m, bi, bp, k-bi);
  t->right = __buildTree(inorder, postorder, m, k+1, bp+k-bi, n-k+bi-1);
  return t;
}
TreeNode* buildTree(vector<int> & inorder, vector<int> & postorder) {
  int n = inorder.size();
  unordered_map<int, int> m;
  for(int i = 0; i < n; i++) m[inorder[i]] = i;
    return __buildTree(inorder, postorder, m, 0, 0, n);
}

