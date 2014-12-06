// review
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *l = head, *t1, *t2, *head2;
        while(f != NULL && l != NULL) {
            f = f->next;
            l = l->next;
            if(l)
                l = l->next;
            else
                return NULL;
            if(f == l && l != NULL) {
                t1 = head;
                t2 = head2 = l->next;
                l->next = NULL;
                while(t1 != t2) {
                    t1 = t1->next;
                    if(!t1)
                        t1 = head2;
                    t2 = t2->next;
                    if(!t2)
                        t2 = head;
                }
                return t1;
            }
        }
        return NULL;
    }
};