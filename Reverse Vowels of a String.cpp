class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> c {'a', 'e', 'i', 'o', 'u', };
        int i = 0, j = s.size()-1; 
        while (i < j) {
            if(c.find(tolower(s[i])) == c.end()) i++;
            else if(c.find(tolower(s[j])) == c.end()) j--;
            else {
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};
