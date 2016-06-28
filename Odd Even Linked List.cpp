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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* l=head, *r=head->next, *headR = head->next;
        while(r && r->next) {
            l->next = r->next;
            l = l->next;
            r->next = l->next;
            r = r->next;
        }
        l->next = headR;
        return head;
    }
};
