class Solution {
public:
    TreeNode *l = NULL;
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        TreeNode *a, *b;
        a = root->left;
        b = root->right;
        if(l) 
            l->right = root;
        l = root;
        l->left = NULL;
        flatten(a);
        flatten(b);
    }
    
};


//review
//version2
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* p = root;
        while(p) {
            TreeNode* l = p->left;
            if(l) {
                TreeNode* r = l;
                while(r->right) r = r->right;
                r->right = p->right;
                p->right = l;
                p->left = NULL;
            }
            p = p->right;
        }
    }
};