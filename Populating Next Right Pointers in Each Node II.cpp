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


// version2
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode HEAD(0);
        HEAD.next = root;
        while(HEAD.next) {
            TreeLinkNode* t = &HEAD;
            TreeLinkNode* p = HEAD.next;
            HEAD.next = NULL;
            for(;p != NULL; p = p->next) {
                if(p->left) {
                    t->next = p->left;
                    t = t->next;
                }
                if(p->right) {
                    t->next = p->right;
                    t = t->next;
                }
            }
        }
    }
};

//version2
//redo
void connect(TreeLinkNode *root) {
  TreeLinkNode HEAD(0);
  HEAD.next = root;
  while(HEAD.next) {
    TreeLinkNode* p = HEAD.next;
    TreeLinkNode* tail = &HEAD;
    HEAD.next = NULL;
    for(;p; p = p->next) {
      if(p->left) {
        tail->next = p->left;
        tail = tail->next;
      }
      if(p->right) {
        tail->next = p->right;
        tail = tail->next;
      }
    }
  }
}

