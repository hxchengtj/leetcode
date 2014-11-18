class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        int a = head->val;
        ListNode *h = head, *l = head->next;
        while(l) {
            if(l->val == h->val) 
                h->next = l->next;
            else 
                h = l;
            l = l->next;
        }
        return head;
    }
};
