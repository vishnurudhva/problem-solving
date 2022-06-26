class Trie {
public:
    map<char, Trie*> trieMap;
    bool isEnd = false;
    void insert(string word) {
        Trie* node = this;
        for (char c: word) {
            if (node->trieMap.find(c) == node->trieMap.end())
                node->trieMap[c] = new Trie();
            node = node->trieMap[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c: word) {
            if (node->trieMap.find(c) == node->trieMap.end())
                return false;
            node = node->trieMap[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string word) {
        Trie* node = this;
        for (char c: word)
            if (node->trieMap.find(c) != node->trieMap.end())
                node = node->trieMap[c];
            else
                return false;
        
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