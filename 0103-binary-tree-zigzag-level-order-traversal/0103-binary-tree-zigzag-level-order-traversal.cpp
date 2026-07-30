class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        // ab mujhe ek tracker bnana left to righjt 
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);  // fixed size to fill from either left to right or right to left

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;
                ans[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(ans);
            leftToRight = !leftToRight;
        }

        return result;
    }
};
