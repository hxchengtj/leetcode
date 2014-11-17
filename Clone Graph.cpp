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
    unordered_map<int, UndirectedGraphNode *> a;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        if(a.find(node->label) != a.end())
            return a[node->label];
        UndirectedGraphNode *n = new UndirectedGraphNode(node->label);
        int i;
        a[n->label] = n;
        for(i = 0; i < node->neighbors.size(); i++) 
            n->neighbors.push_back(cloneGraph(node->neighbors[i]) );
        return n;
    }
};