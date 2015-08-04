bool isAnagram(string s, string t) {
  if(s.size() != t.size()) return false;
  int f[26];
  fill(f, f+26, 0);
  for(char c:s)
    f[c-'a']++;
  for(char c:t) {
    f[c-'a']--;
    if(f[c-'a'] < 0) return false;
  }
  return true;
}

