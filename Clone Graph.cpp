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