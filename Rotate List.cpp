class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int i;
        ListNode HEAD(0), *l = &HEAD, *r = head, *p = head;
        HEAD.next = head;
        for(i = 0; r != NULL; r = r->next, i++);
        if(head == NULL || k%i == 0)
            return head;
        r = head;
        k = k%i;
        for(i = 0; i < k && r; i++) {
            p = r;
            r = r->next;
        }
        if(i < k || !r)
            return head;
        while(r) {
            p = r;
            l = l->next;
            r = r->next;
        }
        if(p != head) {
            p->next = head;
            head = l->next;
            l->next = NULL;
        }
        return head;
    }
};

//redo
ListNode* rotateRight(ListNode* head, int k) {
  if(k < 0 || head == NULL) return NULL;
  int n = 1;
  ListNode* tail = head;
  while(tail->next) {
    tail = tail->next;
    n++;
  }
  k %= n;
  if(k == 0) return head;
  ListNode* p = head;
  for(int i = 0; i < n-k-1; i++) p = p->next;
  ListNode *newhead = p->next;
  p->next = NULL;
  tail->next = head;
  return newhead;
}

