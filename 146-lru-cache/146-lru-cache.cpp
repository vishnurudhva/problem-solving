class LRUCache {
public:
    
    struct List {
        int key;
        int val;
        List* prev;
        List* next;
        
        List(int nodeKey, int nodeValue) {
            key = nodeKey;
            val = nodeValue;
            prev = NULL;
            next = NULL;
        }
    };
    
    int cacheSize, currentSize;
    List *head, *tail;
    unordered_map<int, List*> map;
    
    LRUCache(int capacity) {
        cacheSize = capacity;
        head = new List(-1, -1);
        tail = new List(-1, -1);
        head->next = tail;
        tail->prev = head;
        currentSize = 0;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        
        List* node = map[key];
        
        updateNode(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            List* node = map[key];
            node->val = value;
            updateNode(node);
        } else {
            if(currentSize == cacheSize) {
                List* node = detachNode(tail->prev);
                map.erase(node->key);
                delete node;
                currentSize--;
            }
            
            List* node = new List(key, value);
            moveToFront(node);
            currentSize++;
            map[key] = node;
        }   
    }
    
    void updateNode(List* node) {
        node = detachNode(node);
        moveToFront(node);
    }
    
    void moveToFront(List* node) {
        node->prev = head;
        node->next = head->next;
        
        head->next->prev = node;
        head->next = node;
    }
    
    List* detachNode(List* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */






/*
capacity = 3

[{1, 1}, {2, 6}]


*/




















