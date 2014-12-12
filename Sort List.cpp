class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *l, *r, *p = head, *t;
        int i, n = 0;
        while(p) {
            n++; p = p->next;
        }
        if(n <= 1)
            return head;
        for(i = 0, p = head; i < (n-1)/2; i++)
            p = p->next;
        t = p->next;
        p->next = NULL;
        l = sortList(head);
        r = sortList(t);
        return Merge(l, r);
    }
    ListNode* Merge(ListNode *l, ListNode *r) {
        if(l == NULL)
            return r;
        if(r == NULL)
            return l;
        ListNode HEAD(0), *p = &HEAD;
        while(l != NULL && r != NULL) {
            if(l->val < r->val) {
                p->next = l;
                p = l;
                l = l->next;
            }
            else {
                p->next = r;
                p = r;
                r = r->next;
            }
        }
        if(l)
            p->next = l;
        if(r)
            p->next = r;
        return HEAD.next;
    }
};