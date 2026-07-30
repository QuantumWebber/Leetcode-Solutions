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

    int maxSum=INT_MIN;


    int helper(TreeNode* root){
        if(root==nullptr) return 0;

        int leftSum=max(0,helper(root->left));
        int rightSum=max(0,helper(root->right));

        int currSum=root->val+leftSum+rightSum;

        maxSum=max(maxSum,currSum);

        return root->val+max(leftSum,rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        

        helper(root);
        return maxSum;
    }
};