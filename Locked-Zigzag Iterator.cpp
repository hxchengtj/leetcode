class ZigzagIterator {
  queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    if(!v1.empty()) q.push({v1.begin(), v1.end()});
    if(!v2.empty()) q.push({v2.begin(), v2.end()});
  }

  int next() {
    auto p = q.front();
    q.pop();
    if(p.first+1 != p.second) q.push({p.first+1, p.second});
    return *(p.first);
  }
  bool hasNext() {
    return !q.empty();
  }
};
