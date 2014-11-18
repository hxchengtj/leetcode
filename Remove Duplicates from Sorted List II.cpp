class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode *p = NULL, *h = head, *l = head->next;
        bool b = false;
        while(l) {
            if(l->val == h->val) {
                b = true;
                h->next = l->next;
            }
            else {
                if(b) {
                    if(p)
                        p->next = l;
                    else
                        head = l;
                }
                else
                    p = h;
                h = l;
                b = false;
            }
            l = l->next;
        }
        if(b) {
            if(p)
                p->next = l;
            else
                head = l; 
        }
        return head;
        
    }
};
