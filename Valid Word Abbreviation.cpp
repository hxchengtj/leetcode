class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, m = word.size(), n = abbr.size();
        while(i < m && j < n) {
            if(isdigit(abbr[j])) {
                int k = j;
                while(j < n && isdigit(abbr[j])) j++;
                if(abbr[k] == '0') return false;
                int cnt = stoi(abbr.substr(k, j-k));
                i += cnt;
            }
            else if(word[i] != abbr[j]) return false;
            else {
                i++;
                j++;
            }
        }
        return i == m && j == n;
    }
};
