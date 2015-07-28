// 写的好乱@@
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int i, j = 0, k, l = -1, x, y;
        vector<string> ans;
        string s;
        for(i = 0;i < words.size(); i++) {
            if(l == -1) {
                j = i;
                l = words[i].length();
            }
            else if(l+words[i].length()+1 <= L)
                l = l+words[i].length()+1;
            else {
                s = words[j];
                if(i-1-j == 0) {
                    for(x = 0; x < L-l; x++)
                        s += ' ';
                }
                else {
                    string t;
                    k = (L-l)/(i-j-1);
                    y = L-l - k * (i-j-1);
                    for(x = 0; x <= k; x++)
                        t += ' ';
                    for(x = j+1; x < i; x++)
                        if(x-j-1 < y)
                            s += ' ' + t + words[x];
                        else
                            s += t + words[x];
                }
                ans.push_back(s);
                l = -1;
                i--;
            }
        }
        s = words[j];
        for(i = j+1; i < words.size(); i++)
            s += ' ' + words[i];
        for(i = 0; i < L-l; i++)
            s += ' ';
        ans.push_back(s);
        return ans;
    }
};

//redo
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if(words.size() == 0) return ans;
        int i, j = 0, k, n = words.size(), l = words[0].size();
        for(i = 1; i < n; i++) {
            if(l+1+words[i].size() <= maxWidth) l += 1+words[i].size();
            else {
                string s = words[j];
                if(i == j+1) s.resize(maxWidth, ' ');
                else {
                    int totspace = maxWidth-l;
                    int space = totspace/(i-j-1);
                    int extraspace = totspace%(i-j-1);
                    for(k = j+1; k <= j+extraspace; k++) {
                        s.append(space+2, ' ');
                        s.append(words[k]);
                    }
                    for(;k < i;k++) {
                        s.append(space+1, ' ');
                        s.append(words[k]);
                    }
                }
                ans.push_back(s);
                j = i;
                l = words[i].size();
            }
        }
        string s = words[j];
        for(i = j+1;i < n; i++) {
            s.append(1, ' ');
            s.append(words[i]);
        }
        s.resize(maxWidth, ' ');
        ans.push_back(s);
        return ans;
    }
};

//redo2
vector<string> fullJustify(vector<string>& words, int maxWidth) {
  int n = words.size();
  vector<string> ans;
  if(n == 0) return ans;
  int len = words[0].size(), l = 0;
  for(int i = 1; i < n; i++) {
    if(len+words[i].size()+1 <= maxWidth) len += words[i].size()+1;
    else {
      string line = words[l];
      if(l == i-1) line.append(maxWidth-len, ' ');
      else {
        int avespace = (maxWidth-len)/(i-l-1)+1;
        int extraspace = (maxWidth-len)%(i-l-1);
        int j;
        for(j = l+1; j < extraspace+l+1; j++) {
          line.append(avespace+1, ' ');
          line.append(words[j]);
        }
        for(; j < i; j++) {
          line.append(avespace, ' ');
          line.append(words[j]);
        }
      }
      ans.push_back(line);
      len = words[i].size();
      l = i;
    }
  }
  string line = words[l];
  for(int i = l+1; i < n; i++) {
    line.append(" ");
    line.append(words[i]);
  }
  line.resize(maxWidth, ' ');
  ans.push_back(line);
  return ans;
}

