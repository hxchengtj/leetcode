struct myTreeNode {
  myTreeNode* left;
  myTreeNode* right;
  int val;
  int cnt;
  int dup;
  myTreeNode(int v, int c):val(v), cnt(c), dup(1), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        myTreeNode* root = new myTreeNode(nums.back(), 0);
        vector<int> v(n);
        for(int i = n-2; i >= 0; i--) {
            v[i] = insert_node(root, nums[i]);
        }
        return v;
    }
    int insert_node(myTreeNode* root, int a) {
       myTreeNode* t = root;
       int ret = 0;
       while(t) {
           if(t->val == a) {
               t->dup++;
               ret += t->cnt; break;
           } else if(t->val < a) {
               ret += t->cnt+t->dup;
               myTreeNode* l = t->right;
               if(l) t = l;
               else {
                   t->right = new myTreeNode(a, 0); 
                   break;
               }
           } else if(t->val > a) {
               t->cnt++;
               myTreeNode* l = t->left;
               if(l) t = l;
               else {
                   t->left = new myTreeNode(a, 0); 
                   break;
               }
           }
       }
       return ret;
    }
};
