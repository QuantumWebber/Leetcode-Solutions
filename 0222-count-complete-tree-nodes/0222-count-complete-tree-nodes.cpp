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
    int leftH(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }

    int rightH(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->right;

        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        
       if(!root) return 0;
        int left=leftH(root);
        int right=rightH(root);

        if(left==right) return (1<<left)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};