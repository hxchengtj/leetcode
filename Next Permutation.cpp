//review
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, t, j, k;
        for(i = num.size()-2; i >= 0; i-- ) 
            if(num[i] < num[i+1]) {
                for(j = i+1; j < num.size(); j++)
                    if(num[j] <= num[i])
                        break;
                j--;
                t = num[i];
                num[i] = num[j];
                num[j] = t;
                break;
            }
        for(j = i+1, k = num.size()-1; j < k;j++, k--){
            t = num[j];
            num[j] = num[k];
            num[k] = t;
        }
    }
};

//redo
//version2
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2, j;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
        if(i >= 0) {
            j = n-1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};