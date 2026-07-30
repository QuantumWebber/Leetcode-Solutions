class Solution {
private:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            insert(root, preorder[i]);
        }

        return root;
    }
};
