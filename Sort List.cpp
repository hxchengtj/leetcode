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


//version2
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode HEAD(0);
        HEAD.next = head;
        int n = 1;
        ListNode* tail = &HEAD;
        while(true) {
            ListNode* tail1 = tail;
            for(int i = 0; i < n && tail1->next; i++) tail1 = tail1->next;
            if(tail1->next == NULL && tail == &HEAD) return HEAD.next;
            
            ListNode* tail2 = tail1;
            for(int i = 0; i < n && tail2->next; i++) tail2 = tail2->next;
            
            ListNode* nexthead = tail2->next;
            ListNode* head1 = tail->next, *head2 = tail1->next;
            tail1->next = NULL; tail2->next = NULL;
            while(head1 && head2) {
                ListNode *t;
                if(head1->val <= head2->val) {
                    t = head1;
                    head1 = head1->next;
                }
                else {
                    t = head2;
                    head2 = head2->next;
                }
                tail->next = t;
                tail = t;
            }
            if(head1) {
                tail->next = head1;
                tail = tail1;
            }
            else if(head2) {
                tail->next = head2;
                tail = tail2;
            }
            tail->next = nexthead;
            if(nexthead == NULL) {
                tail = &HEAD;
                n = n << 1;
            }
        }
        return HEAD.next;
    }
};