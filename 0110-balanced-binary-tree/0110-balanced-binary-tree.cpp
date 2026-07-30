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
    pair<bool,int>checkBalanced(TreeNode* root){

        if(root==nullptr)  return {true,0};

        pair<bool,int>left=checkBalanced(root->left);
        pair<bool,int>right=checkBalanced(root->right);


        bool isLeftBalanced=left.first;
        bool isRightBalanced=right.first;



        bool currentBalanced=abs(left.second-right.second)<=1;

        bool isBalanced=isLeftBalanced && isRightBalanced && currentBalanced;

        int height=max(left.second,right.second)+1;
        return {isBalanced,height};
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root).first;
    }
};