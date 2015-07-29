/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
          if(root == NULL)
            return 0;
        int b = 0, e = 1;
        TreeNode** node = new TreeNode* [100000];
        int* depth = new int [100000];

        node[b] = root;
        depth[b] = 1;
        while(b < e)
        {
            if(node[b]->left != NULL)
            {
                node[e] = node[b]->left;
                depth[e] = depth[b]+1;
                e++;
            }
            if(node[b]->right != NULL)
            {
                node[e] = node[b]->right;
                depth[e] = depth[b]+1;
                e++;
            }
            b++;
        }
        return depth[b-1];
    }
};

//version2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


//redo
int maxDepth(TreeNode* root) {
  if(root == NULL) return 0;
  return max(maxDepth(root->left), maxDepth(root->right))+1;
}

