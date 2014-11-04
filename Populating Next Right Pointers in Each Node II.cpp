// Populating Next Right Pointers in Each Node的代码相同 = =
 struct Node {
     TreeLinkNode *n;
     int depth;
     Node(TreeLinkNode *x, int y) : n(x), depth(y) {}
 };
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<Node> node;
        Node front(NULL, 0);
        TreeLinkNode * l;
        int d;
        node.push(Node(root, 1));
        while(node.size()) {
            front = node.front();
            l = front.n;
            d = front.depth;
            if(l->left != NULL) 
                node.push(Node(l->left, d + 1));
            if(l->right != NULL) 
                node.push(Node(l->right, d + 1));
            node.pop();
            if(node.size()) {
                if(node.front().depth == d)
                    l->next = node.front().n;
                else
                    l->next = NULL;
            }
        }
    }
};
