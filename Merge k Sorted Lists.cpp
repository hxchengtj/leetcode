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

//redo
ListNode* mergeKLists(vector<ListNode*>& lists) {
  int k = lists.size();
  ListNode* heap[k];
  int heapsize = 0;
  auto mycmp = [](const ListNode* a, const ListNode* b) {
    return a->val > b->val;
  };
  for(auto l:lists) {
    if(l) {
      heap[heapsize++] = l;
      push_heap(heap, heap+heapsize, mycmp);
    }
  }
  ListNode HEAD(0);
  ListNode* tail = &HEAD;
  while(heapsize) {
    ListNode *t = heap[0];
    pop_heap(heap, heap+heapsize--, mycmp);
    tail->next = t;
    tail = tail->next;

    if(t->next) {
      heap[heapsize++] = t->next;
      push_heap(heap, heap+heapsize, mycmp);
    }
  }
  return HEAD.next;
}

