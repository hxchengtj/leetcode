class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode HEAD1(0), HEAD2(0), *l1 = &HEAD1, *l2 = &HEAD2, *r1 = &HEAD1, *r2 = &HEAD2, *l = head;
        while(l) {
            if(l->val < x) {
                r1->next = l;
                r1 = l;
            }
            else {
                r2->next = l;
                r2 = l;
            }
            l = l->next;
        }
        r1->next = l2->next;
        r2->next = NULL;
        return l1->next;
    }
};
