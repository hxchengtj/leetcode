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


//redo
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *p = head, *q = head->next;
        while(q && p != q) {
            p = p->next;
            q = q->next;
            if(q) q = q->next;
        }
        if(q == NULL) return NULL;
        
        ListNode *t = p;
        ListNode *head2 = t->next;
        ListNode *h1 = head, *h2 = head2;
        while(h1 != h2) {
            if(h1 == t) h1 = head2;
            else h1 = h1->next;
            if(h2 == t) h2 = head;
            else h2 = h2->next;
        }
        return h1;
    }
};