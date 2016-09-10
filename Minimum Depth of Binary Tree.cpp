/* review again */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        int ans = 1;
        TreeNode *t;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            t = q.front();
            if(t == NULL) {
                ans++;
                q.push(NULL);
            }
            else {
                if(t->left == NULL && t->right == NULL)
                    return ans;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            q.pop();

        }
        return ans;
    }
};

//redo
int minDepth(TreeNode* root) {
  if(root == NULL) return 0;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  int ans = 1;
  while(!q.empty()) {
    TreeNode* t = q.front();
    q.pop();
    if(t == NULL) {
      ans++;
      if(!q.empty()) q.push(NULL);
    } else {
      if(!t->left && !t->right) return ans;
      if(t->left) q.push(t->left);
      if(t->right) q.push(t->right);
    }
  }
  return ans;
}

//version2
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};