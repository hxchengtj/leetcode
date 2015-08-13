class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *l = head, *p, *t, *t1;
        int i, n = 0;
        for(n = 0; l != NULL; n++)
            l = l->next;
        l = head;
        for(i = 0; i < n/2; i++)
            l = l->next;
        p = NULL;
        for(; i < n; i++) {
            t = l->next;
            l->next = p;
            p = l;
            l = t;
        }
        l = head;
        for(i = 0; i < n/2; i++) {
            t = l->next;
            t1 = p->next;
            l->next = p;
            p->next = t;
            l = t;
            p = t1;
        }
        if(l)
            l->next = NULL;
    }
};

//redo
ListNode* reverse_list(ListNode* head) {
  if(head == NULL) return head;
  ListNode* p = head, *np = head->next;
  head->next = NULL;
  while(np) {
    ListNode* t = np->next;
    np->next = p;
    p = np;
    np = t;
  }
  return p;
}
void reorderList(ListNode* head) {
  if(head == NULL || head->next == NULL) return ;
  ListNode* p = head, *q = head->next;
  while(q) {
    q = q->next;
    if(q) {
      q = q->next;
      p = p->next;
    }
  }
  ListNode* head1 = reverse_list(p->next);
  p->next = NULL;
  ListNode HEAD(0);
  ListNode* tail = &HEAD;
  while(head && head1) {
    tail->next = head;
    head = head->next;
    tail = tail->next;
    tail->next = head1;
    head1 = head1->next;
    tail = tail->next;
  }
  if(head) tail->next = head;
  if(head1) tail->next = head1;
}

