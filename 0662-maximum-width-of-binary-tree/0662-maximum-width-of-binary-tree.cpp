class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;  // If the root is null, the width is 0
        
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;  // Queue to store nodes along with their indices
        q.push({root, 0});  // Start with the root node at index 0

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            unsigned long long leftMost = q.front().second;  // Index of the leftmost node
            unsigned long long rightMost = q.back().second;  // Index of the rightmost node
            maxWidth = max(maxWidth, int(rightMost - leftMost + 1));  // Update max width

            for (int i = 0; i < levelSize; ++i) {
                auto [node, index] = q.front();  // Get the current node and its index
                q.pop();
                // Add child nodes to the queue with their respective indices
                if (node->left) q.push({node->left, 2 * index});
                if (node->right) q.push({node->right, 2 * index + 1});
            }
        }

        return maxWidth;  // Return the maximum width found
    }
};
