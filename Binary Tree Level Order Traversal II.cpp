class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int b = 0, e = 1;
        vector<vector<int>> order;
        if(root == NULL) {
            return order;
        }
        TreeNode** node = new TreeNode* [1000000];
        int* depth = new int [1000000];
        node[0] = root;
        depth[0] = 1;
        while (b < e) {
            if(node[b]->right) {
                node[e] = node[b]->right;
                depth[e] = depth[b]+1;
                e++;
            }
            if(node[b]->left) {
                node[e] = node[b]->left;
                depth[e] = depth[b]+1;
                e++;
            }
            b++;
        }
        int i = b-1;
        vector<int> t;
        int d = depth[i];
        for(i = b - 1; i >= 0; i--) {
            if(depth[i] == d)
                t.push_back(node[i]->val);
            else {
                order.push_back(t);
                t.clear();
                t.push_back(node[i]->val);
                d = depth[i];
            }
        }
        order.push_back(t);
        return order;
    }
};


//redo
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if(t == NULL) {
                ans.push_back(v);
                v.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else {
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//redo2
vector<vector<int>> levelOrderBottom(TreeNode* root) {
  vector<vector<int>> ans;
  vector<int> v;
  if(root == NULL) return ans;
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    TreeNode* t = q.front();
    q.pop();
    if(t == NULL) {
      ans.push_back(v);
      v.clear();
      if(!q.empty()) q.push(NULL);
    }
    else {
      v.push_back(t->val);
      if(t->left) q.push(t->left);
      if(t->right) q.push(t->right);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

