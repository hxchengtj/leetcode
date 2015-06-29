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