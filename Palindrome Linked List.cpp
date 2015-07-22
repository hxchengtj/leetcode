class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* p = head, *q = head->next;
        while(q) {
            q = q->next;
            if(q) { 
                q = q->next;
                p = p->next;
            }
        }
        ListNode *prev = p, *head2;
        head2 = reverse_list(prev->next);
        p = head;
        q = head2;
        while(p && q) {
            if(p->val != q->val) {
                prev->next = reverse_list(head2);
                return false;
            }
            p = p->next;
            q = q->next;
        }
        prev->next = reverse_list(head2);
        return true;
        
    }
    ListNode* reverse_list(ListNode* head) {
        ListNode *p = head, *nextp = head->next;
        head->next = NULL;
        while(nextp) {
            ListNode* t = nextp->next;
            nextp->next = p;
            p = nextp;
            nextp = t;
        }
        return p;
    }
};