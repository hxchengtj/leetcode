class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[26];
    bool end;
    TrieNode() {
        end = false;
        for(int i = 0;i < 26; i++)
            child[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* t = root;
        for(int i = 0; i < word.size(); i++) {
            int j = word[i]-'a';
            if(t->child[j] == NULL)
                t->child[j] = new TrieNode();
            t = t->child[j];
        }
        t->end = true;
    }

};


class Solution {
public:
    vector<string> v;
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* r, string &s) {
        char c = board[x][y];
        if(c == '\0' || r->child[c-'a'] == NULL)
            return;
        s.push_back(c);
        board[x][y] = '\0';
        r = r->child[c-'a'];
        if(r->end == true) {
            v.push_back(s);
            r->end = false;
        }

        int f[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i = 0; i < 4; i++) {
            int k = f[i][0] + x;
            int l = f[i][1] + y;
            if(k >= 0 && k < board.size() && l >= 0 && l < board[0].size())
                dfs(board, k, l, r, s);
        }
        board[x][y] = c;
        s.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        v.clear();
        if(board.size() == 0 || board[0].size() == 0)
            return v;
        Trie t;
        string s;
        for(int i = 0; i < words.size(); i++)
            t.insert(words[i]);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                dfs(board, i, j, t.root, s);
        return v;
    }
};


//redo
class TrieNode {
  public:
    bool isEnd;
    TrieNode* child[26];
    TrieNode() {
      isEnd = false;
      for(int i = 0; i < 26; i++)
        child[i] = NULL;
    }
};

class Trie{
  public:
    TrieNode* root;
    Trie(){
      root = new TrieNode();
    }
    void addWord(string word) {
      TrieNode* t = root;
      for(char c:word) {
        if(t->child[c-'a'] == NULL) t->child[c-'a'] = new TrieNode();
        t = t->child[c-'a'];
      }
      t->isEnd = true;
    }
};
vector<string> ans;
string s;
void __findWords(vector<vector<char>>& board, int x, int y, TrieNode* root) {
  char c = board[x][y];
  if(c == 0 || root->child[c-'a'] == NULL) return;
  root = root->child[c-'a'];
  s.push_back(c);
  if(root->isEnd) {
    ans.push_back(s);
    root->isEnd = false;
  }
  board[x][y] = 0;
  int f[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  for(int i = 0; i < 4; i++) {
    int x1 = f[i][0]+x, y1 = f[i][1]+y;
    if(x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size())
      __findWords(board, x1, y1, root);
  }
  s.pop_back();
  board[x][y] = c;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  Trie trie;
  for(auto& word:words) trie.addWord(word);
  ans.clear();
  if(trie.root->isEnd) ans.push_back("");
  for(int i = 0; i < board.size(); i++)
    for(int j = 0; j < board[0].size(); j++)
      __findWords(board, i, j, trie.root);
  return ans;
}

//version2
class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd = false;
    TrieNode() {
        for(int i = 0; i < 26; i++) 
            child[i] = NULL;
    }
    ~TrieNode() {
        for(int i = 0; i < 26; i++)
            if(child[i]) delete child[i];
    }
};

TrieNode* buildTrie(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for(auto& w:words) {
        TrieNode* t = root;
        for(char c:w) {
            if(t->child[c-'a'] == NULL) t->child[c-'a'] = new TrieNode();
            t = t->child[c-'a'];
        }
        t->isEnd = true;
    }
    return root;
}
class Solution {
public:
    void dfs(vector<vector<char>>& board, TrieNode* root, vector<string>& ans, string& s, int x, int y) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) 
            return;
        char c = board[x][y];
        if(c == '#' || root->child[c-'a'] == NULL) return;
        s.push_back(c);
        root = root->child[c-'a'];
        if(root->isEnd) 
            ans.push_back(s);
        //记得此处去重
        root->isEnd = false;
        board[x][y] = '#';
        dfs(board, root, ans, s, x+1, y);
        dfs(board, root, ans, s, x-1, y);
        dfs(board, root, ans, s, x, y+1);
        dfs(board, root, ans, s, x, y-1);
        board[x][y] = c;
        s.pop_back();
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || board[0].size() == 0 || words.size() == 0) return {};
        TrieNode* root = buildTrie(words);
        vector<string> ans;
        string s;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                dfs(board, root, ans, s, i, j);
        return ans;
    }
};
