class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *HEAD = new ListNode(0), *l, *t, *p;
        HEAD->next = head;
        l = head;
        p = HEAD;
        while(l && l->next) {
            t = l->next;
            l->next = t->next;
            t->next = l;
            p->next = t;
            p = l;
            l = l->next;
        }
        return HEAD->next;
    }
};

//redo
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
    ListNode* swapPairs(ListNode* head) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* p = &HEAD;
        while(p->next && p->next->next) {
            ListNode* q = p->next;
            ListNode* qn = q->next;
            ListNode* a = qn->next;
            p->next = qn;
            qn->next = q;
            q->next = a;
            p = q;
        }
        return HEAD.next;
    }
};

//redo
ListNode* swapPairs(ListNode* head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* pre = &HEAD;
  while(pre->next && pre->next->next) {
    ListNode* p = pre->next, * q = p->next;
    p->next = q->next;
    q->next = p;
    pre->next = q;
    pre = p;
  }
  return HEAD.next;
}

