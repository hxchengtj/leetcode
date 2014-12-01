 // review
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        int len1, len2;
        ListNode *l1, *l2, *l = NULL;
        for(len1 = 0, l1 = headA; l1 != NULL; len1++, l1 = l1->next);
        for(len2 = 0, l2 = headB; l2 != NULL; len2++, l2 = l2->next);
        for(l1 = headA; len1 > len2; len1--, l1 = l1->next);
        for(l2 = headB; len2 > len1; len2--, l2 = l2->next);
        for(;l1 && l2; l1 = l1->next, l2 = l2->next) {
            if(l1->val != l2->val)
                l = NULL;
            else if(l == NULL)
                l = l1;
        }
        return l;
            
    }
};
