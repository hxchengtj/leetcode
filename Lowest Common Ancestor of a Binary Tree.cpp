class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> father;
        queue<TreeNode*> que;
        if(root == NULL) return NULL;
        que.push(root);
        que.push(NULL);
        int lp = 0, lq = 0, l = 0;
        bool fp = false, fq = false;
        while(!que.empty()) {
            if(fp && fq) break;
            TreeNode* t = que.front();
            que.pop();
            if(t == NULL) {
                l++;
                if(!que.empty()) que.push(NULL);
            }
            else {
                if(t == p) { 
                    lp = l;
                    fp = true;
                }
                if(t == q) {
                    lq = l;
                    fq = true;
                }
                if(t->left) {
                    father[t->left] = t;
                    que.push(t->left);
                }
                if(t->right) {
                    father[t->right] = t;
                    que.push(t->right);
                }
            }
        }
        if(!fp || !fq) return NULL;
        TreeNode *ancp = p, *ancq = q;
        while(lp > lq) {
            ancp = father[ancp];
            lp--;
        }
        while(lq > lp) {
            ancq = father[ancq];
            lq--;
        }
        while(ancp != ancq) {
            ancp = father[ancp];
            ancq = father[ancq];
        }
        return ancp;
        }

};