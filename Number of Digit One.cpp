/* review again */
//review
class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        int ans = 0;
        long long t = 10;
        while(n >= t/10) {
            ans += (n/t)*(t/10);
            int a = (n/(t/10))%10;
            if(a == 1) ans += (n%(t/10))+1;
            else if(a > 1) ans += t/10;
            t *= 10;
        }
        return ans;
    }
};

//redo
int countDigitOne(int n) {
  if(n <= 0) return 0;
  long long t = 1;
  int ans = 0;
  while(n >= t) {
    ans += (n/(10*t))*t;
    int a = (n/t)%10;
    if(a == 1) ans += (n%t)+1;
    else if(a > 1) ans += t;
    t = t*10;
  }
  return ans;
}

