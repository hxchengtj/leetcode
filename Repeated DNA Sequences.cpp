class Solution {
public:
    int transint(string & a) {
        int b = 0, c;
        for(int i = 0;i < 10; i++) {
            b = b << 2;
            switch(a[i]) {
                case 'A': b = b | 0;    break;
                case 'C': b = b | 1;    break;
                case 'G': b = b | 2;    break;
                case 'T': b = b | 3;
            }
        }
        return b;
    }
    int changeint(int a, char c) {
        int b =  ( (~(1 << 31)) >> 13);
        a = ((a & b) << 2);
        switch(c) {
            case 'A': a = a | 0;    break;
            case 'C': a = a | 1;    break;
            case 'G': a = a | 2;    break;
            case 'T': a = a | 3;
        }
        return a;
    }
    string transstring(int a) {
        string s;
        int b = (3 << 18), j = 18, k;
        for(int i = 0; i < 10; i++) {
            k = (a & b) >> j;
            switch(k) {
                case 0: s.append("A");  break;
                case 1: s.append("C");  break;
                case 2: s.append("G");  break;
                case 3: s.append("T");
            }
            b = b >> 2;
            j -= 2;
        }
        return s;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> v;
        string a = s.substr(0, 10), c;
        int b = transint(a);
        m.insert(make_pair(b, 0));
        for(int i = 10; i < s.size(); i++) {
            b = changeint(b, s[i]);
            if(m.find(b) == m.end())
                m.insert(make_pair(b, 0));
            else {
                m[b]++;
                if(m[b] == 1) {
                    c = transstring(b);
                    v.push_back(c);
                }
            }
        }
        return v;
    }
};

//redo
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int c[26];
        c['A'-'A'] = 0;
        c['C'-'A'] = 1;
        c['G'-'A'] = 2;
        c['T'-'A'] = 3;
        int a = (1<<20)-1, val = 0;
        unordered_map<int, int> m;
        vector<string> v;
        for(int i = 0; i < s.size(); i++) {
            val = ((val << 2) & a )| c[s[i]-'A'];
            if(i >= 9) {
                m[val]++;
                if(m[val] == 2)
                    v.push_back(s.substr(i-9, 10));
            }
        }
        return v;
    }
};

//redo2
vector<string> findRepeatedDnaSequences(string s) {
  char DNA[26];
  DNA['A'-'A'] = 0;
  DNA['C'-'A'] = 1;
  DNA['G'-'A'] = 2;
  DNA['T'-'A'] = 3;
  int a = (1<<20)-1, val = 0;
  unordered_map<int, int> m;
  vector<string> ans;
  for(int i = 0; i < s.size(); i++) {
    val = ((val << 2) | DNA[s[i]-'A']) & a;
    if(i >= 9) {
      m[val]++;
      if(m[val] == 2) ans.push_back(s.substr(i-9, 10));
    }
  }
  return ans;
}

