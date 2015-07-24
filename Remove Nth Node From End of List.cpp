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

//redo
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* p = &HEAD;
  for(int i = 0; i <= n; i++) p = p->next;
  ListNode* q = &HEAD;
  while(p) {
    p = p->next;
    q = q->next;
  }
  ListNode* nthnode = q->next;
  q->next = nthnode->next;
  delete nthnode;
  return HEAD.next;
}

