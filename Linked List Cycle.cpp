class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *l = head;
        while(f != NULL && l != NULL) {
            f = f->next;
            l = l->next;
            if(l == NULL)
                return false;
            l = l->next;
            if(f == l && f != NULL)
                return true;
        }
        return false;
    }
};


//redo
bool hasCycle(ListNode* head) {
  if(head == NULL || head->next == NULL) return false;
  ListNode* p = head, *q = head->next;
  while(q && p != q) {
    p = p->next;
    q = q->next;
    if(q) q = q->next;
  }
  return q != NULL;
}

