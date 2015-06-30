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

