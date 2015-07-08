class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l = NULL, *p = NULL, *p1;
        int a = 0, val = 0;
        while(l1 != NULL || l2 != NULL) {
            if(l1 != NULL && l2 != NULL)
                val = a + l1->val + l2->val;
            else if(l1 != NULL)
                val = a + l1->val;
            else
                val = a + l2->val;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            a = val / 10;
            val = val % 10;
            p1 = new ListNode(val);
            if(p)
                p->next = p1;
            p = p1;
            if(!l)
                l = p;
        }   
        if(a){
            p1 = new ListNode(a);
            if(p)
                p->next = p1;
            p = p1;
            if(!l)
                l = p; 
        }
        return l;
    }
};

//version2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode HEAD(0);
        ListNode* p = &HEAD;
        int c = 0;
        while(l1 || l2 || c) {
            if(l1) {
                c += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                c += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(c%10);
            p = p->next;
            c = c/10;
        }
        return HEAD.next;
    }
};