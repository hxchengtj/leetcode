/* review again */
class Solution {
public:
    int findupper(vector<int> &v, int n) {
        int l = 0, r = v.size(), m;
        while(l < r) {
            m = l + (r-l)/2;
            if(v[m] < n)
                l = m+1;
            else
                r = m;
        }
        return l;
    }
    void quicksort(vector<int> & v, int l, int r) {
        if (l >= r)
            return;
        int m = l;
        for(int i = l+1; i < r; i++) {
            if(v[i] < v[l]) {
                swap(v[m], v[i]);
                swap(v[m+1], v[i]);
                m += 1;
            }
        }
        quicksort(v, l, m);
        quicksort(v, m+1, r);

    }
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.begin()+k);
        quicksort(v, 0, k);
        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] > v[0]) {
                v.erase(v.begin());
                int j = findupper(v, nums[i]);
                v.insert(v.begin()+j, nums[i]);
            }
        }
        return v[0];
    }

};


//version2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n || n == 0) return INT_MIN;
        int l = 0, r = n;
        while(true) {
            int m = l;
            for(int i = l+1; i < r; i++) {
                if(nums[i] > nums[m]) {
                    swap(nums[i], nums[m]);
                    swap(nums[m+1], nums[i]);
                    m++;
                }
            }
            if(m == k-1) return nums[m];
            else if(m < k-1) l = m+1;
            else r = m;
        }
    }
};


//version2
//redo
int findkth(vector<int> &nums, int k) {
  int n = nums.size();
  if(n < k || k <= 0) return 0;
  int l = 0, r = n;
  while(true) {
    int m = l;
    for(int i = l+1; i < r; i++) {
      if(nums[i] > nums[m]) {
        swap(nums[i], nums[m]);
        swap(nums[i], nums[++m]);
      }
    }
    if(m == k-1) return nums[m];
    else if(m > k-1) r = m;
    else l = m+1;
  }
}


//version3
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int a = nums[l], b = l;
        l++;
        while(l <= r) {
            //这样做使得和a相等的可能在左侧或右侧, 这样更容易分到中间
            if(nums[l] < a && nums[r] > a) {
                swap(nums[l++], nums[r--]);
            }
            else if(nums[l] >= a) l++;
            else if(nums[r] <= a) r--;
        }
        swap(nums[r], nums[b]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = n-1;
        k--;
        while(l <= r) {
            int m = partition(nums, l, r);
            if(m == k) return nums[m];
            else if(m < k) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
