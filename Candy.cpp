/* review again */
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> up(ratings.size()), down(ratings.size());
        int i;
        for(i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1])
                up[i] = up[i-1]+1;
            else
                up[i] = 0;
        }
        for(i = ratings.size()-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1])
                down[i] = down[i+1]+1;
            else
                down[i] = 0;
        }
        int ans = 0;
        for(i = 0; i < ratings.size(); i++)
            ans += max(up[i], down[i]) + 1;
        return ans;

    }
};

//redo
int candy(vector<int>& ratings) {
  int n = ratings.size();
  vector<int> up(n, 1), down(n, 1);
  for(int i = 1; i < n; i++) {
    if(ratings[i] > ratings[i-1]) up[i] = up[i-1]+1;
    else up[i] = 1;
  }
  for(int i = n-2; i >= 0; i--) {
    if(ratings[i] > ratings[i+1]) down[i] = down[i+1]+1;
    else down[i] = 1;
  }
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans += max(up[i], down[i]);
  return ans;
}

