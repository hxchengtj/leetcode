class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *l = head;
        while(f != NULL && l != NULL) {
            f = f->next;
            l = l->next;
            if(l == NULL)
                return false;
            l = l->next;
            if(f == l && f != NULL)
                return true;
        }
        return false;
    }
};