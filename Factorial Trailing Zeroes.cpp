/* review again */
class Solution {
public:
    int trailingZeroes(int n) {
        int a = 0;
        while(n) {
            a += n/5;
            n /= 5;
        }
        return a;
    }
};


//redo
int trailingZeroes(int n) {
  int ans = 0;
  while(n) {
    ans += n/5;
    n /= 5;
  }
  return ans;
}

