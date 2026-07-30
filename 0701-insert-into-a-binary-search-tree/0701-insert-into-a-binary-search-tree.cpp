class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* toInsert = new TreeNode(val);
        if (root == NULL) {
            return toInsert;
        }

        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left == NULL) {
                    curr->left = toInsert;
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right == NULL) {
                    curr->right = toInsert;
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }
};
