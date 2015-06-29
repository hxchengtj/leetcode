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