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

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* t = root;
        for(int i = 0; i < word.size(); i++) {
            int j = word[i]-'a';
            if(t->child[j] == NULL) 
                t->child[j] = new TrieNode();
            t = t->child[j];
        }
        t->end = true;        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* t = root;
        for(int i = 0;i < word.size(); i++) {
            if(word[i] != '.') {
                int j = word[i]-'a';
                if(t->child[j] == NULL)
                    return false;
                t = t->child[j];
            }
            else {
                for(int k = 0;k < 26; k++)
                    if(t->child[k] != NULL && search_dot(word, i+1, t->child[k]))
                        return true;
                return false;
            }
        }
        if(t->end == true)
            return true;
        return false;        
    }
    bool search_dot(string & word, int l, TrieNode* t) {
        for(int i = l;i < word.size(); i++) {
            if(word[i] != '.') {
                int j = word[i]-'a';
                if(t->child[j] == NULL)
                    return false;
                t = t->child[j];
            }
            else {
                for(int k = 0;k < 26; k++)
                    if(t->child[k] != NULL && search_dot(word, i+1, t->child[k]))
                        return true;
                return false;
            }            
        }
        if(t->end == true)
            return true;
        return false;
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");