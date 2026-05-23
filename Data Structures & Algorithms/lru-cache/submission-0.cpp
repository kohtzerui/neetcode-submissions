class LRUCache {
private:
    // 1. The Custom Node
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache; // Maps key to Node pointer
    Node* left;  // LRU Dummy Head
    Node* right; // MRU Dummy Tail

    // Helper: Remove a node from anywhere in the linked list
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: Insert a node at the right (Most Recently Used position)
    void insert(Node* node) {
        Node* prevNode = right->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        // Initialize dummy nodes
        left = new Node(0, 0);
        right = new Node(0, 0);
        // Stitch them together
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Mark as most recently used
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // If the key exists, remove the old node first
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key]; // Free old memory
        }
        
        // Create new node, add to map, and insert as MRU
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        
        // Check capacity
        if (cache.size() > capacity) {
            // The LRU node is the one right after the left dummy
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key); // This is why we store the key inside the Node!
            delete lru;            // Free memory
        }
    }
};