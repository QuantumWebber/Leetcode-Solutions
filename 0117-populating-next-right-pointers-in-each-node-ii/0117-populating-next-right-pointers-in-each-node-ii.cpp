class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        queue<Node*> q; // Queue to hold Node* not int
        q.push(root);
        
        while (!q.empty()) {
            int len = q.size();
            Node* prev = nullptr;

            while (len--) {
                Node* temp = q.front(); 
                q.pop();

                if (prev) prev->next = temp; // Connect the previous node with the current one

                prev = temp; // Update prev to current node

                if (temp->left) q.push(temp->left);   // Push left child
                if (temp->right) q.push(temp->right); // Push right child
            }

            // After finishing the level, set the next of the last node to NULL
            prev->next = nullptr;
        }

        return root;
    }
};
