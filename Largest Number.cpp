class Solution {
public:
    bool mycompare(int a, int b) {
        string s1 = to_string(a) + to_string(b), s2 = to_string(b) + to_string(a);
        return s1 > s2;
    }
    void quicksort(vector<int>& nums, int l, int r) {
        if(l >= r)
            return;
        int m = l;
        for(int i = l+1; i < r; i++) {
            if(mycompare(nums[i], nums[m])) {
                swap(nums[m], nums[i]);
                swap(nums[m+1], nums[i]);
                m++;
            }
        }
        quicksort(nums, l, m);
        quicksort(nums, m+1, r);
    }
    string largestNumber(vector<int>& nums) {
        quicksort(nums, 0, nums.size());
        string s;
        if(nums[0] == 0)
            return "0";
        for(int i = 0; i < nums.size(); i++) {
            s.append(to_string(nums[i]));
        }
        
        return s;
    }
};