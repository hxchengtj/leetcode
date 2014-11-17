//review
//ะดิฮมห><
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *h = head, *h1 = head, *p1 = NULL, *lm, *h2;
        int i = 1, j = 0;
        for(i = 1; i < m; h = h->next, i++) 
            if(i == m-1)
                p1 = h;
        lm = h;
        h1 = h->next;
        for(i = m+1; i <= n; i++) {
            h2 = h1->next;
            h1->next = h;
            h = h1;
            h1 = h2;
        }
        lm->next = h1;
        if(p1)
            p1->next = h;
        else
            head = h;
        return head;
    }
};