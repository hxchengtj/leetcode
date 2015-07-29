/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
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


//redo
void connect(TreeLinkNode *root) {
  TreeLinkNode HEAD(0);
  HEAD.next = root;
  while(HEAD.next) {
    TreeLinkNode* f = HEAD.next;
    HEAD.next = NULL;
    TreeLinkNode* tail = &HEAD;
    while(f) {
      if(f->left) {
        tail->next = f->left;
        tail = tail->next;
      }
      if(f->right) {
        tail->next = f->right;
        tail = tail->next;
      }
      f = f->next;
    }
  }
}

