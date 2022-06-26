class Trie {
private:
    vector<Trie*> trieMap;
    bool isEnd = false;
public:
    Trie() { trieMap = vector<Trie*>(26); }
    void insert(string word) {
        Trie* node = this;
        for (char c: word) {
            if (!node->trieMap[c - 'a'])
                node->trieMap[c - 'a'] = new Trie();
            node = node->trieMap[c- 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            if (!node->trieMap[c - 'a'])
                return false;
            node = node->trieMap[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string word) {
        Trie* node = this;
        for (char c: word) {
            if (!node->trieMap[c - 'a'])
                return false;
            node = node->trieMap[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */