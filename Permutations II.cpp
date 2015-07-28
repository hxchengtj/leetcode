// review
struct node {
    int num;
    int a;      // num数目
    node(int x, int y):num(x), a(y) {};
};
class Solution {
public:
    vector<node> v;
    vector<vector<int> > ans;
    vector<int> b;
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        v.clear();
        ans.clear();
        b.clear();
        b.resize(num.size());
        if(!num.size())
            return ans;
        int i, j = 1;
        for(i = 1; i < num.size(); i++) {
            if(num[i] == num[i-1])
                j++;
            else {
                node t(num[i-1], j);
                v.push_back(t);
                j = 1;
            }
        }
        node t(num[i-1], j);
        v.push_back(t);
        dfs(0, num.size());
        return ans;
    }
    void dfs(int n, int m) {
        if(n == m) {
            ans.push_back(b);
            return;
        }
        for(int i = 0; i < v.size(); i++) {
            if(v[i].a > 0){
                v[i].a--;
                b[n] = v[i].num;
                dfs(n+1, m);
                v[i].a++;
            }
        }
    }
};

//redo
//version2

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() == 0)
            return ret;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> a;
        a.push_back(make_pair(nums[0], 1));
        for(int i = 1; i < nums.size(); i++) {
            if(a.back().first == nums[i])
                a.back().second++;
            else
                a.push_back(make_pair(nums[i], 1));
        }
        vector<int> v(nums.size(), 0);
        dfs(a, v, ret, 0);
        return ret;
    }
    void dfs(vector<pair<int, int>> &a, vector<int> &v, vector<vector<int>> &ret, int x) {
        if(x == v.size()) {
            ret.push_back(v);
            return;
        }
        for(int i = 0;i < a.size(); i++) {
            if(a[i].second > 0) {
                a[i].second--;
                v[x] = a[i].first;
                dfs(a, v, ret, x+1);
                a[i].second++;
            }
        }
    }
};

//redo
vector<vector<int>> ans;
vector<int> v;
vector<vector<int>> permuteUnique(vector<int>& nums) {
  ans.clear(); v.clear();
  if(nums.size() == 0) return ans;
  sort(nums.begin(), nums.end());
  vector<pair<int, int>> numsv;
  int k = 1;
  for(int i = 1; i <= nums.size(); i++) {
    if(i == nums.size() || nums[i] != nums[i-1]) {
      numsv.push_back(make_pair(nums[i-1], k));
      k = 1;
    } else k++;
  }
  dfs(numsv, nums.size());
  return ans;
}

void dfs(vector<pair<int, int>>& numsv, int n) {
  if(n == 0) {
    ans.push_back(v);
    return;
  }
  for(auto &p:numsv) {
    if(p.second > 0) {
      v.push_back(p.first);
      p.second--;
      dfs(numsv, n-1);
      p.second++;
      v.pop_back();
    }
  }
}


