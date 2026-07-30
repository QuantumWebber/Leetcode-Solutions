class MapSum {
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd;
        int value;

        TrieNode() {
            isEnd = false;
            value = 0;

            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };
    TrieNode* root;

    // DFS function
    int dfs(TrieNode* node) {

        if (node == NULL)
            return 0;

        int sum = 0;

        // If a word ends here, add its value
        if (node->isEnd)
            sum += node->value;

        // Visit all children
        for (int i = 0; i < 26; i++) {
            sum += dfs(node->children[i]);
        }

        return sum;
    }

    

public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        
        TrieNode* node=root;

        for(char ch:key){
            int idx=ch-'a';


            if(node->children[idx]==NULL)   node->children[idx]=new TrieNode();

            node=node->children[idx];
        }

        node->isEnd=true;
        node->value=val;
        
    }
    
    int sum(string prefix) {
        
        TrieNode* node = root;

        // Reach prefix node
        for (char ch : prefix) {

            int idx = ch - 'a';

            if (node->children[idx] == NULL)
                return 0;

            node = node->children[idx];
        }

        return dfs(node);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */