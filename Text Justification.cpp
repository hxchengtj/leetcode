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
