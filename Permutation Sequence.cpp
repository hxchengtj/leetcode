class Solution {
public:
    string getPermutation(int n, int k) {
        int a[n+1], i, j, l, m;
        vector<bool> b(n+1);
        string s;
        a[0] = 1;
        k--;
        for(i = 1; i <= n; i++)
            a[i] = i * a[i-1];
        for(i = n-1; i >= 0; i--) {
            l = k/a[i];
            m = 0;
            for(j = 1; j <= n; j++)
                if(!b[j]) {
                    if(l == m) {
                        s += (j+'0');
                        b[j] = true;
                        break;
                    }
                    m++;
                }
            k = k%a[i];
        }
        return s;
    }
};

//redo
string getPermutation(int n, int k) {
  int t = 1;
  vector<bool> visited(n, false);
  string ans;
  for(int i = 2; i < n; i++)
    t *= i;
  k--;
  for(int i = n-1; i >= 0; i--) {
    int j = k/t+1, l = 0;
    for(int a = 0; a < n; a++) {
      if(visited[a] == false) l++;
      if(j == l) {
        visited[a] = true;
        ans.push_back(a+'1');
        break;
      }
    }
    k = k%t;
    if(i > 0) t /= i;
  }
  return ans;
}

