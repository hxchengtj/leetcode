class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        sum.clear();
        int n = nums.size();
        sum.resize(n+1);
        for(int i = 0; i < n; i++) {
            sum[i+1] += sum[i]+nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
