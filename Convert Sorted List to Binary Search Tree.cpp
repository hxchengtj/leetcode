// review
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* l = head;
        int i = 0;
        while(l) {
            i++;
            l = l->next;
        }
        return dfs(head, i).first;
    }
    pair<TreeNode *, ListNode *> dfs(ListNode *h, int a) {
        if(!h || a <= 0) {
            TreeNode *b = NULL;
            return make_pair(b, h);
        }
        pair<TreeNode *, ListNode *> p, ret;
        p = dfs(h, a/2);
        ret.first = new TreeNode(p.second->val);
        ret.first->left = p.first;
        p = dfs(p.second->next, a-a/2-1);
        ret.first->right = p.first;
        ret.second = p.second;
        return ret;
    }
};


//redo
TreeNode* sortedListToBST(ListNode* head) {
  int n = 0;
  for(ListNode* p = head; p; p = p->next) n++;
  return dfs(0, n, head);
}

TreeNode* dfs(int l, int r, ListNode*& p) {
  if(l >= r) return NULL;
  int m = l + (r-l)/2;
  TreeNode* left = dfs(l, m, p);
  TreeNode* t = new TreeNode(p->val);
  p = p->next;
  TreeNode* right = dfs(m+1, r, p);
  t->left = left;
  t->right = right;
  return t;
}

