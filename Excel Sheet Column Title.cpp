/* review again */
//review
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        int i;
        while(n) {
            char c = 'A' + ((n-1)%26);
            s = c + s;
            n = (n-1)/26;
        }
        return s;
    }
};

//redo
string convertToTitle(int n) {
  string ans;
  while(n) {
    ans.push_back((n-1)%26+'A');
    n = (n-1)/26;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

