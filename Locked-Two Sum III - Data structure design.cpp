class TwoSum {
  unordered_map<int, int> count;
public:
  void add(int number) {
    count[number]++;
  }

  bool find(int value) {
    for(auto &p:count) {
      int t = value-p.first;
      if((t == p.first && p.second > 1) || (t != p.first && count.find(t) != count.end())) return true;
    }
    return false;
  }
};
