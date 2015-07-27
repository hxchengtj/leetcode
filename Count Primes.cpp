class Solution {
public:
    int countPrimes(int n) {
        bool prime[n];
        for(int i = 0; i < n; i++)
            prime[i] = true;
        int l = 2, r = 0;
        while(l < n) {
            for(int i = 2*l; i <= n; i += l)
                prime[i] = false;
            r++;
            l++;
            while(l < n && prime[l] == false)
                l++;
        }
        return r;
    }
};

//redo
int countPrime(int n) {
  vector<bool> isP(n+1, true);
  int ans = 0;
  for(int i = 2; i < n; i++) {
    if(isP[i]) {
      ans++;
      for(int j = i*2; j < n; j += i)
        isP[j] = false;
    }
  }
  return ans;
}

