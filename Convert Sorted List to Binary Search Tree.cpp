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