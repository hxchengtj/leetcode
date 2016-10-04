/* review again */
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

//version2
struct SegTreeNode {
    int begin;
    int end;
    int sum;
    SegTreeNode* left, *right;
    SegTreeNode(int b, int e, int s):begin(b), end(e), sum(s), left(NULL), right(NULL) {}
};
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> sum(n+1);
        for(int i = 0; i < n; i++)
            sum[i+1] = sum[i] + nums[i];
        root = buildTree(sum, 0, n-1);
    }

    void update(int i, int val) {
        modifyTree(root, val, i);
    }

    int sumRange(int i, int j) {
        return queryTree(root, i, j);
    }
private:
    SegTreeNode* root;
    SegTreeNode* buildTree(vector<int>& sum, int begin, int end) {
        if(begin > end) return NULL;
        SegTreeNode* t = new SegTreeNode(begin, end, sum[end+1]-sum[begin]);
        if(end - begin > 0) {
            int mid = begin+(end-begin)/2;
            t->left = buildTree(sum, begin, mid);
            t->right = buildTree(sum, mid+1, end);
        }
        return t;
    }
    void modifyTree(SegTreeNode* root, int val, int idx) {
        if(!root || idx < root->begin || idx > root->end) 
            return;
        if(root->begin == idx && root->end == idx)
            root->sum = val;
        else {
            modifyTree(root->left, val, idx);
            modifyTree(root->right, val, idx);
            root->sum = root->left->sum + root->right->sum;
        }
    }
    int queryTree(SegTreeNode* root, int i, int j) {
        if(!root || j < root->begin || i > root->end)
            return 0;
        if(root->begin >= i && root->end <= j) return root->sum;
        else return queryTree(root->left, i, j) + queryTree(root->right, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
