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


//redo
class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
      q = root;
    }
    bool hasNext() {
      return q || !stk.empty();
    }
    int next() {
      while(q) {
        stk.push(q);
        q = q->left;
      }
      TreeNode* t = stk.top();
      stk.pop();
      q = t->right;
      return t->val;
    }
  private:
    TreeNode* q;
    stack<TreeNode*> stk;
};

