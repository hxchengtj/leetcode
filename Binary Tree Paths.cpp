vector<TreeNode*> path;
vector<string> ans;
void __binaryTreePaths(TreeNode* root) {
  path.push_back(root);
  if(root->left == NULL && root->right == NULL) {
    ans.push_back(to_string(path[0]->val));
    for(int i = 1; i < path.size(); i++)
      ans.back().append("->"+to_string(path[i]->val));
  }
  if(root->left) __binaryTreePaths(root->left);
  if(root->right) __binaryTreePaths(root->right);
  path.pop_back();
}
vector<string> binaryTreePaths(TreeNode* root) {
  path.clear(); ans.clear();
  if(root == NULL) return {};
  __binaryTreePaths(root);
  return ans;
}

//version2
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right)
            return {to_string(root->val)};
        vector<string> v = binaryTreePaths(root->left), ans;
        for(auto& a:v) ans.push_back(to_string(root->val)+"->"+a);
        v = binaryTreePaths(root->right);
        for(auto& a:v) ans.push_back(to_string(root->val)+"->"+a);
        return ans;
    }
};
