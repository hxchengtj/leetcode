class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l = NULL, *p1 = NULL, *p = NULL;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                p1 = l1;
                l1 = l1->next;
            }
            else {
                p1 = l2;
                l2 = l2->next;
            }
            if(p)
                p->next = p1;
            if(l == NULL)
                l = p1;
            p = p1;
        }
        while(l1 != NULL) {
            p1 = l1;
            if(p)
                p->next = p1;
            if(l == NULL)
                l = p1;
            p = p1;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            p1 = l2;
            if(p)
                p->next = p1;
            if(l == NULL)
                l = p1;
            p = p1;
            l2 = l2->next;
        }
        return l;
    }
};
