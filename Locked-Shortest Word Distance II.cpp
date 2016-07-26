class WordDistance {
public:
  WordDistance(vector<string> words) {
    for(int i = 0; i < words.size(); i++) MAP[words[i]].push_back(i);
  }
  int shortest(string word1, string word2) {
    vector<int> v1 = MAP[word1], v2 = MAP[word2];
    int i = 0, j = 0, ans = INT_MAX;
    while(i < v1.size() && j < v2.size()) {
      ans = min(ans, abs(v1[i]-v2[j]));
      if(v1[i] < v2[j]) i++;
      else j++;
    }
    return ans;
  }
private:
  unordered_map<string, vector<int>> MAP;
};

