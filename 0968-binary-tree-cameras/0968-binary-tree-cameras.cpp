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
    int cameras=0;

    int dfs(TreeNode* node){
        if (node==nullptr) return 1;

        int leftState=dfs(node->left);
        int rightState=dfs(node->right);



        if(leftState==2 || rightState==2){
            // need camera

            cameras++;
            return 0;
        }

        if(leftState==0 || rightState==0){
            return 1; // child camera parent monitor 
        }

        return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==2) cameras++;
        return cameras;
    }
};