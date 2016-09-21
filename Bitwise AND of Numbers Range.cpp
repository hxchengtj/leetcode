/* review again */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int r = n-m+1;
        int a = m & n, b = -1;
        for(int i = 1; i > 0 && i < r; i = i<<1)
            b = b << 1;
        a = a & b;
        return a;
    }
};


//redo
int rangeBitwiseAnd(int m, int n) {
  int r = n-m+1;
  int ans = m & n, a = -1, i;
  for(i = 0; i < 31 && (1 << i) < r; i++);
  return ans & (a << i);
}

//redo
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = m & n, num = n-m+1;
        for(int i = 0; i < 31 && (1 << i) < num; i++) 
            ans &= (~(1 << i));
        return ans;
    }
};
