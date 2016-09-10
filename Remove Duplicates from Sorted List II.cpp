/* review again */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode *p = NULL, *h = head, *l = head->next;
        bool b = false;
        while(l) {
            if(l->val == h->val) {
                b = true;
                h->next = l->next;
            }
            else {
                if(b) {
                    if(p)
                        p->next = l;
                    else
                        head = l;
                }
                else
                    p = h;
                h = l;
                b = false;
            }
            l = l->next;
        }
        if(b) {
            if(p)
                p->next = l;
            else
                head = l;
        }
        return head;

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* p = &HEAD;
        while(p->next) {
            ListNode* q = p->next;
            bool flag = false;
            while(q->next && q->val == q->next->val) {
                flag = true;
                ListNode* t = q->next;
                q->next = t->next;
                delete t;
            }
            if(flag) {
                p->next = q->next;
                delete q;
            }
            else
                p = p->next;
        }
        return HEAD.next;
    }
};

//redo
ListNode* deleteDuplicates(ListNode* head) {
  ListNode HEAD(0);
  HEAD.next = head;
  ListNode* tail = &HEAD, *p = head;
  while(p){
    if(p->next && p->next->val == p->val) {
      while(p->next && p->next->val == p->val) {
        ListNode* t = p->next;
        p->next = t->next;
        delete t;
      }
      tail->next = p->next;
      delete p;
    } else tail = tail->next;
    p = tail->next;
  }
  return HEAD.next;
}

