class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // If one of the child is null, we should not consider it in min calculation
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        // If both children are present, take the minimum of the two depths
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
