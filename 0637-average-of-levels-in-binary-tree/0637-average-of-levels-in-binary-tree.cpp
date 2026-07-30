class Solution {
private:
    vector<double> levelOrderAverage(TreeNode* root) {
        vector<double> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double sum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                sum += currentNode->val;

                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
            
            result.push_back(sum / levelSize);
        }

        return result;
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        return levelOrderAverage(root);
    }
};
