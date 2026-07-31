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
class Solution {private:

    // Count paths starting exactly from current node
    int countPath(TreeNode* root, long long target){

        if(root==nullptr)
            return 0;

        int cnt = 0;

        // Agar current node se target complete ho gaya
        if(root->val == target)
            cnt++;

        // Left aur Right dono taraf continue karo
        cnt += countPath(root->left, target - root->val);
        cnt += countPath(root->right, target - root->val);

        return cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        
     if(root==nullptr)
            return 0;

        // 1. Current node se start hone wale paths
        int ans = countPath(root, targetSum);

        // 2. Left subtree ko starting point banao
        ans += pathSum(root->left, targetSum);

        // 3. Right subtree ko starting point banao
        ans += pathSum(root->right, targetSum);

        return ans;
    }
};