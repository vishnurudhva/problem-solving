class TrieNode {
public:
    char chr;
    unordered_map<char, TrieNode*> trieMap;
    bool isEnd;
    TrieNode(char chr) {
        this->chr = chr;
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* head;
    Trie() {
        head = new TrieNode('0');
    }
    
    void insert(string word) {
        TrieNode* node = head;
        for (char c: word) {
            if (node->trieMap.find(c) == node->trieMap.end()) {
                TrieNode* newNode = new TrieNode(c);
                node->trieMap[c] = newNode;
                node = newNode;
            } else {
                node = node->trieMap[c];
            }
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = head;
        for (char c: word) {
            if (node->trieMap.find(c) != node->trieMap.end()) {
                node = node->trieMap[c];
            } else {
                return false;
            }
        }
        
        return node->isEnd;
    }
    
    bool startsWith(string word) {
        TrieNode* node = head;
        for (char c: word) {
            if (node->trieMap.find(c) != node->trieMap.end()) {
                node = node->trieMap[c];
            } else {
                return false;
            }
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