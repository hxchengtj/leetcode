class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *l = head, *p, *t, *t1;
        int i, n = 0;
        for(n = 0; l != NULL; n++) 
            l = l->next;
        l = head;
        for(i = 0; i < n/2; i++)
            l = l->next;
        p = NULL;
        for(; i < n; i++) {
            t = l->next;
            l->next = p;
            p = l;
            l = t;
        }
        l = head;
        for(i = 0; i < n/2; i++) {
            t = l->next;
            t1 = p->next;
            l->next = p;
            p->next = t;
            l = t;
            p = t1;
        }
        if(l)
            l->next = NULL;
    }
};
