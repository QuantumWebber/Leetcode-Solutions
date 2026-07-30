class Solution {
private:
    int currentVal;
    int currentCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void handleValue(int val) {
        if (val != currentVal) {
            currentVal = val;
            currentCount = 0;
        }
        currentCount++;
        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes.clear();
            modes.push_back(currentVal);
        } else if (currentCount == maxCount) {
            modes.push_back(currentVal);
        }
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};
