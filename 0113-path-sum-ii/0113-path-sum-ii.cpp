class Solution {
private:

    void allPaths(TreeNode* root, int targetSum,
                  vector<vector<int>>& ans,
                  vector<int>& results) {

        if(root == nullptr)
            return;

        results.push_back(root->val);

        // Leaf node
        if(!root->left && !root->right) {

            if(targetSum == root->val)
                ans.push_back(results);
        }
        else {

            allPaths(root->left,
                     targetSum - root->val,
                     ans,
                     results);

            allPaths(root->right,
                     targetSum - root->val,
                     ans,
                     results);
        }

        // Backtracking
        results.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> results;

        allPaths(root, targetSum, ans, results);

        return ans;
    }
};