/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:

    int find(TreeNode* root, string a){

        if(root == nullptr)
            return 0;

        if(root->left == nullptr && root->right == nullptr){
            return stoi(a + to_string(root->val));
        }

        return find(root->left, a + to_string(root->val)) +
               find(root->right, a + to_string(root->val));
    }

public:
    int sumNumbers(TreeNode* root) {

        if(root == nullptr)
            return 0;

        string a = "";

        return find(root, a);
    }
};