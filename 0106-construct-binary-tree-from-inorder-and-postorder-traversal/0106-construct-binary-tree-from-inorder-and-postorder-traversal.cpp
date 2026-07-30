/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int findPosition(vector<int>& inorder, int element) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == element)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,
                    int &index, int inorderStart, int inorderEnd) {

        // Base Case
        if (index < 0 || inorderStart > inorderEnd)
            return nullptr;

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        int position = findPosition(inorder, element);

        // IMPORTANT: Right first, then Left
        root->right = solve(postorder, inorder, index, position + 1, inorderEnd);
        root->left = solve(postorder, inorder, index, inorderStart, position - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postorderIndex = postorder.size() - 1;

        return solve(postorder, inorder, postorderIndex, 0, inorder.size() - 1);
    }
};