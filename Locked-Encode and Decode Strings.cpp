class Codec {  
public:  
    // Encodes a list of strings to a single string.  
    string encode(vector<string>& strs) {  
      string ans;
      for(auto& s:strs)
        ans += to_string(s.size()) + "#" + s;
      return ans;
    }  
    // Decodes a single string to a list of strings.  
    vector<string> decode(string s) {  
      vector<string> v;
      int i = 0;
      while(i < s.size()) {
        string num;
        while(s[i] != '#') num.push_back(s[i++]);
        int n = stoi(num);
        v.push_back(s.substr(++i, n));
        i += n;
      }
      return v;
    }  
};  
// Your Codec object will be instantiated and called as such:  
// Codec codec;  
// codec.decode(codec.encode(strs));  
