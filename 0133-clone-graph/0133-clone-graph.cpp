class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        mp[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {

            Node* curr = q.front();
            q.pop();

            for(Node* neighbor : curr->neighbors) {

                if(mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                // connect clone nodes
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return mp[node];
    }
};