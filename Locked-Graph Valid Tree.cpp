//redo 
class Solution {
public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if(edges.size() != n-1) return false;
    vector<int> father(n);
    for(int i = 0; i < n; i++) father[i] = i;
    for(auto &e: edges) {
      int f1 = find_father(father, e.first), f2 = find_father(father, e.second);
      if(f1 == f2) return false;
      father[f1] = f2;
    }
    return true;
  }
  int find_father(vector<int> &father, int a) {
    if(father[a] != a) father[a] = find_father(father, father[a]);
    return father[a];
  }
};
