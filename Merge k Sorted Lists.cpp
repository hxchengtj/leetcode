// review
//不会分析复杂度～><
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int i;
        vector<ListNode *> v;
        auto cmp = [](const ListNode *x, const ListNode *y) { return x->val > y->val;}; // ??
        for(ListNode* l:lists) 
            if(l)
                v.push_back(l);
        make_heap(v.begin(), v.end(), cmp);
        ListNode HEAD(0), *p = &HEAD, *t;
        while(v.size()) {
            pop_heap(v.begin(), v.end(), cmp);
            p->next = new ListNode(v.back()->val);
            p = p->next;
            t = v.back()->next;
            v.pop_back();
            if(t) {
                v.push_back(t);
                push_heap(v.begin(), v.end(), cmp);
            }
        }
        return HEAD.next;
    }
};
