//常空间
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *front, *next, *left;
        front = root;
        while(front) {
            next = front;
            front = NULL;
            left = NULL;
            while(next) {
                if(next->left) {
                    if(!left) {
                        left = next->left;
                        front = left;
                    }
                    else {
                        left->next = next->left;
                        left = next->left;
                    }
                }
                if(next->right) {
                    if(!left) {
                        left = next->right;
                        front = left;
                    }
                    else {
                        left->next = next->right;
                        left = next->right;
                    }
                }
                next = next->next;
            }
        }
    }
};
