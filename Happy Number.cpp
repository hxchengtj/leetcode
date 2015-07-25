class Solution {
public:
    int cal_n(int n) {
        int m = 0, a;
        while(n != 0) {
            a = n%10;
            m += a*a;
            n = n/10;
        }
        return m;
    }
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while(n != 1) {
            if(m.find(n) != m.end())
                return false;
            m.insert(make_pair(n, 0));
            n = cal_n(n);
        }
        return true;
    }
};

//redo
class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0) return false;
        unordered_set<int> s;
        while(n != 1) {
            if(s.find(n) != s.end()) return false;
            else s.insert(n);
            int t = 0;
            while(n) {
                int a = n%10;
                t += a*a;
                n = n/10;
            }
            n = t;
        }
        return true;
    }
};

//redo2
bool isHappy(int n) {
  if(n <= 0) return false;
  unordered_set<int> s;
  while(n != 1 && s.find(n) == s.end()) {
    s.insert(n);
    int t = 0;
    while(n) {
      t += (n%10)*(n%10);
      n = n/10;
    }
    n = t;
  }
  return n == 1;
}

