class Solution {
public:
   vector<int> searchRange(int A[], int n, int target) {
       int l = 0, r = n-1, mid, ansl, ansr;
       vector<int> ans;
       
       while (l <= r){
           mid = (l+r)/2;
           if (A[mid] >= target) r = mid-1;
           else l = mid+1;
       }
       ansl = r+1;
       l = 0; r = n-1;
       while (l <= r){
           mid = (l+r)/2;
           if (A[mid] <= target) l = mid+1;
           else r = mid-1;
       }
       ansr = l-1;
       if (ansl > ansr) ansl = ansr = -1;
       ans.push_back(ansl);
       ans.push_back(ansr);
       
       return ans;
   }
};