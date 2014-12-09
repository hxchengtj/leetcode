class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode HEAD(0), *l = &HEAD, *lf, *p, *q, *t;
        HEAD.next = head;
        l = head;
        lf = &HEAD;
        while(l != NULL) {
            p = HEAD.next;
            q = &HEAD;
            t = l->next;
            while(p != l) {
                if(l->val < p->val) {
                    q->next = l;
                    l->next = p;
                    lf->next = t;
                    break;
                }
                q = p;
                p = p->next;
            }
            if(p == l)
                lf = l;
            l = t;
        }
        return HEAD.next;
    }
};