/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode a = ListNode(0);
        a.next = head;
        ListNode* l = &a, *r = head;
        while(r) {
            ListNode *t = r->next;
            if(r->val == val) {
                l->next = t;
                r = t;
            }
            else {
                l = r;
                r = t;
            }
        }
        return a.next;
    }
};


//redo
ListNode* removeElements(ListNode* head, int val) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* p = &HEAD;
  while(p->next) {
    if(p->next->val == val) {
      ListNode* t = p->next;
      p->next = t->next;
      delete t;
    }
    else p = p->next;
  }
  return HEAD.next;
}

