class ValidWordAbbr {
  unordered_map<string, unordered_set<string>> m;
public:
  ValidWordAbbr(vector<string> &dictionary) {
    for(auto& s:dictionary) {
      string t;
      if(s.size() > 2) 
        t = s[0] + to_string(s.size()-2) + s.back();
      else t = s;
      m[t].insert(s);
    }
  }
  bool isUnique(string word) {
    string t;
    if(word.size() > 2) t = word[0] + to_string(word.size()-2) + word.back();
    else t = word;
    return m.find(t) == m.end() || (m[t].count(word) == m[t].size());
  }
};
