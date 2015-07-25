//redo
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *>& m) {
        if(node == NULL) return NULL;
        if(m.find(node->label) != m.end()) return m[node->label];
        UndirectedGraphNode *a = new UndirectedGraphNode(node->label);
        m[node->label] = a;
        for(auto n: node->neighbors)
            a->neighbors.push_back(clone(n, m));
        return a;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode *> m;
        return clone(node, m);
    }
};

//redo2
UndirectedGraphNode* dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> & m) {
  if(node == NULL) return NULL;
  if(m.find(node) != m.end()) return m[node];
  UndirectedGraphNode* t = new UndirectedGraphNode(node->label);
  m[node] = t;
  for(auto n:node->neighbors)
      t->neighbors.push_back(dfs(n, m));
  return t;
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
  return dfs(node, m);
}

