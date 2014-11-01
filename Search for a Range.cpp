class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l, r, mid;
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        l = 0;
        r = n-1;
        mid = (l+r)/2;
        int tmpl, tmpr;
        tmpl = 0;
        tmpr = n-1;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if (A[mid] > target) {
                r = mid-1;
                tmpr = r;
            }
            else if (A[mid] < target) {
                l = mid + 1;
                tmpl = l;
            }
            else 
            {
                if (mid == 0 || A[mid-1] < target)
                {
                    ans[0] = mid;
                    tmpl = mid;
                    break;
                }
                else 
                   r = mid-1;
            }
        }
        l = tmpl;
        r = tmpr;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(A[mid] > target)
                r = mid-1;
            else if(mid == n-1 || A[mid+1] > target)
            {
                ans[1] = mid;
                break;
            }
            else
                l = mid+1;
        }
        return ans;
        
    }

};

