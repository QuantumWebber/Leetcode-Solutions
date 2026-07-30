class Solution {
private:
    bool checkPathSum(TreeNode* root, int targetSum) {
        
        if (root == nullptr) {
            return false;
        }

    
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }


        int remainingSum = targetSum - root->val;
        return checkPathSum(root->left, remainingSum) || checkPathSum(root->right, remainingSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPathSum(root, targetSum);
    }
};