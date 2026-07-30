class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* curr = root;

        while(curr != NULL || !stack.empty()) {
            while(curr != NULL) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            result.push_back(curr->val); // Corrected this line

            curr = curr->right;
        }

        return result;
    }
};