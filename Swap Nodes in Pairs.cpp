class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *HEAD = new ListNode(0), *l, *t, *p;
        HEAD->next = head;
        l = head;
        p = HEAD;
        while(l && l->next) {
            t = l->next;
            l->next = t->next;
            t->next = l;
            p->next = t;
            p = l;
            l = l->next;
        }
        return HEAD->next;
    }
};