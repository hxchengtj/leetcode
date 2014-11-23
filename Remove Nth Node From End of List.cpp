// review
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode HEAD(0), *l = &HEAD, *r = head;
        HEAD.next = head;
        for(int i = 0; i < n; i++)
            r = r->next;
        while(r != NULL) {
            l = l->next;
            r = r->next;
        }
        l->next = l->next->next;
        return HEAD.next;
    }
};