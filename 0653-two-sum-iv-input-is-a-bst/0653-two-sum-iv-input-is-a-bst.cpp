class Solution {
private:
    unordered_set<int> st;

    bool solve(TreeNode* root, int k) {

        if (root == NULL)
            return false;

        int need = k - root->val;

        if (st.find(need) != st.end())
            return true;

        st.insert(root->val);

        return solve(root->left, k) || solve(root->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        return solve(root, k);
    }
};