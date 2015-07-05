class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int l = n;
        for(int i = 0; i < l; i++) {
            if(A[i] == elem) {
                swap(A[i], A[l-1]);
                l--;
                i--;
            }
        }
        return l;
    }
};

//redo
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), j = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] != val) nums[j++] = nums[i];
        return j;
    }
};
