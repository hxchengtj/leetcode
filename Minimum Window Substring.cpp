class Solution {
public:
    string minWindow(string S, string T) {
        int i, l = 0, r = 0, x = S.size(), y = T.size(), z;
        unordered_map<char, int> m;
        unordered_map<char, int>::iterator iter, iter1;
        string ans = S + "*";
        for(i = 0; i < T.length(); i++) {
            iter = m.find(T[i]);
            if(iter == m.end())
                m[T[i]] = 1;
            else
                iter->second++;
        }
        z = T.length();
        while(r < x) {
            iter = m.find(S[r]);
            if(iter != m.end()) {
                if(iter->second > 0)
                    z--;
                iter->second--;
                for( ;l < r; l++) {
                    iter1 = m.find(S[l]);
                    if(iter1 != m.end()) {
                        if(iter1->second < 0)
                            iter1->second++;
                        else
                            break;
                    }
                }
                if(z == 0 && r-l+1 < ans.length())
                    ans = S.substr(l, r-l+1);
            }
            r++;
        }
        if(ans.length() > x)
            ans = "";
        return ans;
    }
};