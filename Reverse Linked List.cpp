/* review again */
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* l = head;
        ListNode* r = head->next;
        head->next = NULL;
        while(r != NULL) {
            ListNode *t = r->next;
            r->next = l;
            l = r;
            r = t;
        }
        return l;
    }
};

//redo
ListNode* reverseList(ListNode* head) {
  if(head == NULL) return NULL;
  ListNode* tail = head;
  while(tail->next) {
    ListNode* t = tail->next;
    tail->next = t->next;
    t->next = head;
    head = t;
  }
  return head;
}

//version2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode HEAD(0);
        HEAD.next = head;
        if(head == NULL) return head;
        ListNode* p = head->next;
        head->next = NULL;
        while(p) {
            ListNode* t = p->next;
            p->next = HEAD.next;
            HEAD.next = p;
            p = t;
        }
        return HEAD.next;
    }
};
