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