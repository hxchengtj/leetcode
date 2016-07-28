class Solution {
public:
  ListNode* plusOne(ListNode* head) {
    ListNode* HEAD = new ListNode(0);
    HEAD->next = head;
    ListNode* h = HEAD, *t = NULL;
    while(h) {
      if(h->val != 9) t = h;
      h = h->next;
    }
    t->val += 1;
    if(t == HEAD) head = HEAD;
    else delete HEAD;
    while(t->next) {
      t->next->val = 0;
      t = t->next;
    }
    return head;
  }
};
