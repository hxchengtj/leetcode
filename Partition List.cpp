/* review again */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode HEAD1(0), HEAD2(0), *l1 = &HEAD1, *l2 = &HEAD2, *r1 = &HEAD1, *r2 = &HEAD2, *l = head;
        while(l) {
            if(l->val < x) {
                r1->next = l;
                r1 = l;
            }
            else {
                r2->next = l;
                r2 = l;
            }
            l = l->next;
        }
        r1->next = l2->next;
        r2->next = NULL;
        return l1->next;
    }
};

//redo
ListNode* partition(ListNode* head, int x) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* tail1 = &HEAD, * tail2 = &HEAD;
  while(tail2->next) {
    ListNode* p = tail2->next;
    if(p->val >= x) tail2 = tail2->next;
    else {
      if(tail1 == tail2) tail1 = tail2 = tail2->next;
      else {
        ListNode* t = p->next;
        tail2->next = t;
        p->next = tail1->next;
        tail1->next = p;
        tail1 = p;
      }
    }
  }
  return HEAD.next;
}

//version2
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode HEAD1(0), HEAD2(0);
        ListNode* l = &HEAD1, *r = &HEAD2;
        while(head) {
            if(head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        l->next = HEAD2.next;
        r->next = NULL;
        return HEAD1.next;
    }
};
