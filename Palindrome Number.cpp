class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int a = x, b = 1;
        while(a > 9) {
            b *= 10;
            a /= 10;
        }
        while(x > 0) {
            if(x%10 != x/b)
                return false;
            x -= b * (x/b);
            b /= 100;
            x /= 10;
        }
        return true;
    }
};

//redo
bool isPalindrome(int x) {
  if(x < 0) return false;
  int i = 1, j = 1;
  while(x/i >= 10) i *= 10;
  while(i > j) {
    if((x/i)%10 != (x/j)%10) return false;
    i /= 10;
    j *= 10;
  }
  return true;
}

