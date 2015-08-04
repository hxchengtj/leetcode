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

//redo
ListNode* deleteDuplicates(ListNode* head) {
  if(head == NULL) return NULL;
  ListNode* p = head;
  while(p->next) {
    ListNode* t = p->next;
    if(p->val == t->val) {
      p->next = t->next;
      delete t;
    }
    else p = p->next;
  }
  return head;
}

