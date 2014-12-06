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
