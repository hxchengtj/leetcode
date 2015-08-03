class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode HEAD(0), *l = &HEAD, *lf, *p, *q, *t;
        HEAD.next = head;
        l = head;
        lf = &HEAD;
        while(l != NULL) {
            p = HEAD.next;
            q = &HEAD;
            t = l->next;
            while(p != l) {
                if(l->val < p->val) {
                    q->next = l;
                    l->next = p;
                    lf->next = t;
                    break;
                }
                q = p;
                p = p->next;
            }
            if(p == l)
                lf = l;
            l = t;
        }
        return HEAD.next;
    }
};

//redo
ListNode* insertionSortList(ListNode* head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* l = &HEAD, *r = &HEAD;
  while(r->next) {
    ListNode* t = r->next;
    r->next = t->next;
    while(l->next != t->next && l->next->val < t->val) l = l->next;
    t->next = l->next;
    l->next = t;
    if(l == r) r = t;
    l = &HEAD;
  }
  return HEAD.next;
}


