struct SegTreeNode {
    int start;
    int end;
    int sum;
    SegTreeNode* left;
    SegTreeNode* right;
    SegTreeNode(int s, int e, int sum_):start(s), end(e), sum(sum_), left(NULL), right(NULL) {} 
};
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> sum(n+1);
        for(int i = 0; i < n; i++) sum[i+1] = sum[i]+nums[i];
        root = build_tree(sum, 0, n-1);
        nums_v = nums;
    }

    void update(int i, int val) {
        modify_tree(root, i, val);
        nums_v[i] = val;
    }

    int sumRange(int i, int j) {
        return query_tree(root, i, j);
    }
private:
    SegTreeNode* root;
    vector<int> nums_v;
    SegTreeNode* build_tree(vector<int>& sum, int start, int end) {
        if(start > end) return NULL;
        SegTreeNode* t = new SegTreeNode(start, end, sum[end+1]-sum[start]);
        if (end-start >= 1) {
            t->left = build_tree(sum, start, start+(end-start)/2);
            t->right = build_tree(sum, start+(end-start)/2+1, end);
        }
        return t;
    }
    void modify_tree(SegTreeNode* root, int index, int val) {
        if (root && root->start <= index && root->end >= index) {
            root->sum += val-nums_v[index];
            modify_tree(root->left, index, val);
            modify_tree(root->right, index, val);
        }
    }
    int query_tree(SegTreeNode* root, int start, int end) {
        if(!root || root->start > end || root->end < start) return 0;
        if(root->start >= start && root->end <= end) return root->sum;
        return query_tree(root->left, start, end) + query_tree(root->right, start, end);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
