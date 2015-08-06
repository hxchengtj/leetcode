class Solution {
public:
    unordered_map<RandomListNode *, RandomListNode *> m;
    RandomListNode *copyRandomList(RandomListNode *head) {
        m[NULL] = NULL;
        return dfs(head);

    }
    RandomListNode *dfs(RandomListNode *h) {
        if(m.find(h) != m.end())
            return m[h];
        RandomListNode *nh = new RandomListNode(h->label);
        m[h] = nh;
        nh->next = dfs(h->next);
        nh->random = dfs(h->random);
        return nh;
    }
};

//redo
RandomListNode *copyRandomList(RandomListNode *head) {
  unordered_map<RandomListNode*, RandomListNode*> m;
  return __copyRandomList(head, m);
}

RandomListNode *__copyRandomList(RandomListNode *head, unordered_map<RandomListNode*, RandomListNode*>& m) {
  if(head == NULL) return NULL;
  if(m.find(head) != m.end()) return m[head];
  RandomListNode* t = new RandomListNode(head->label);
  m[head] = t;
  t->next = __copyRandomList(head->next, m);
  t->random = __copyRandomList(head->random, m);
  return t;
}

