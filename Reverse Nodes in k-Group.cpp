 // hard
 // review
 // 链表常常写晕=.=
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *l = head, *p, *t, *a, *b = &HEAD;
        int i, j;
        while(l) {
            a = l;
            p = l;
            l = l->next;
            for(i = 1; i < k && l; i++) {
                t = l->next;
                l->next = p;
                p = l;
                l = t;
            }
            if(i < k) {
                l = p->next;
                p->next = NULL;
                for(j = 1; j < i && l; j++) {
                    t = l->next;
                    l->next = p;
                    p = l;
                    l = t;
                }
                break;
            }
            b->next = p;
            a->next = l;
            b = a;
        }
        return HEAD.next;
    }
};

//redo
ListNode* reverseKGroup(ListNode* head, int k) {
  if(k <= 1) return head;
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* prev = &HEAD;
  while(prev->next) {
    ListNode* p = prev;
    for(int i = 0; i < k && p; i++) p = p->next;
    if(p == NULL) break;

    ListNode* tail = prev->next;
    for(int i = 0; i < k-1; i++) {
      ListNode* t = tail->next;
      tail->next = t->next;
      t->next = prev->next;
      prev->next = t;
    }
    prev = tail;
  }
  return HEAD.next;
}

