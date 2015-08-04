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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* t = root;
        for(int i = 0; i < word.size(); i++) {
            int j = word[i]-'a';
            if(t->child[j] == NULL)
                return false;
            t = t->child[j];
        }
        if(t->end == true)
            return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for(int i = 0; i < prefix.size(); i++) {
            int j = prefix[i]-'a';
            if(t->child[j] == NULL)
                return false;
            t = t->child[j];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


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

class Trie {
  public:
    Trie() {
      root = new TrieNode();
    }

    void insert(string word) {
      TrieNode* t = root;
      for(char c:word) {
        if(t->child[c-'a'] == NULL) t->child[c-'a'] = new TrieNode();
        t = t->child[c-'a'];
      }
      t->isEnd = true;
    }

    bool search(string word) {
      TrieNode* t = root;
      for(char c:word) {
        if(t->child[c-'a'] == NULL) return false;
        t = t->child[c-'a'];
      }
      return t->isEnd;
    }

    bool startsWith(string prefix) {
      TrieNode* t = root;
      for(char c:prefix) {
        if(t->child[c-'a'] == NULL) return false;
        t = t->child[c-'a'];
      }
      return true;
    }
  private:
    TrieNode* root;
};

