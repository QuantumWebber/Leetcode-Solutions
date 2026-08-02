class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;   // key -> node ka pointer
    Node* head;                      // dummy head : iske baad MRU
    Node* tail;                      // dummy tail : iske pehle LRU

    // node ko list se bahar nikaal do
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // node ko head ke turant baad daal do (MRU position)
    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        insertAtFront(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        moveToFront(node);          // ab ye most recently used hai
        return node->value;
    }

    void put(int key, int value) {
        // Case 1 : key pehle se maujood hai
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToFront(node);
            return;
        }

        // Case 2 : nayi key, aur cache full hai -> LRU evict karo
        if ((int)mp.size() == capacity) {
            Node* lru = tail->prev;   // sabse purana used node
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;               // memory free
        }

        // Case 3 : naya node insert
        Node* node = new Node(key, value);
        insertAtFront(node);
        mp[key] = node;
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};