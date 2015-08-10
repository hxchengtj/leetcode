class Solution {
public:
    int sqrt(int x) {
        if(x < 0)
            return -1;
        if(x == 0)
            return 0;
        int m, l = 1, r = x;
        while(l <= r) {
            m = l + (r-l)/2;    // 防止int越界
            if(m > x / m)       // 防止int越界
                r = m-1;
            else
                l = m+1;
        }
        return r;             //舍掉小数位
    }
};

//redo
int mySqrt(int x) {
  if(x < 0) return -1;
  if(x == 0) return x;
  int l = 1, r = x;
  while(l <= r) {
    int m = l+(r-l)/2;
    if(m > x/m) r = m-1;
    else l = m+1;
  }
  return r;
}
