class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            // Traverse the current level
            for (int i = 0; i < levelSize; i++) { // i should start from 0 and run while i < levelSize
                TreeNode* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }

        // Reverse the result to get the bottom-up order
        reverse(result.begin(), result.end());
        
        return result;
    }
};
