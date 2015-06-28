/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode *root) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       return !s.empty(); 
    }

    //好像不是O(1)时间的。。。
    /** @return the next smallest number */
    int next() {
        TreeNode *t = s.top();
        int v = t->val;
        s.pop();
        t = t->right;
        while(t) {
            s.push(t);
            t = t->left;
        }
        return v;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */