/* review again */
int hIndex(vector<int>& citations) {
  int n = citations.size();
  int l = 0, r = n;
  while(l < r) {
    int m = l+(r-l)/2;
    if(citations[m] < (n-m)) l = m+1;
    else if(citations[m] > (n-m)) r = m;
    else return n-m;
  }
  return n-l;
}

//version2
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, n = citations.size(), r = n;
        while(l < r) {
            int m = l + (r-l)/2;
            if(citations[m] < n-m) l = m+1;
            else r = m;
        }
        return n-l;
    }
};
