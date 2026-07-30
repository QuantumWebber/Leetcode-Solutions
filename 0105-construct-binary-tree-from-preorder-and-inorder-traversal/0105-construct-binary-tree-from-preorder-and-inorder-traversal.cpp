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
    TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int &index, int inorderStart, int inorderEnd){
        // base case of recursion 

        // if my index would overflow size of array or inorderStart > inorderEnd
        if(index >= inorder.size() || inorderStart > inorderEnd){
            return nullptr;
        }

        int element = preorder[index++]; // root element from preorder
        TreeNode* root = new TreeNode(element);

        int position = findPosition(inorder, element); // use to find position of element in inorder

        // recursive calls for left and right subtree
        root->left = solve(preorder, inorder, index, inorderStart, position - 1);
        root->right = solve(preorder, inorder, index, position + 1, inorderEnd);

        return root;
    }

    int findPosition(vector<int>& inorder, int element){
        int position = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == element){
                position = i;
                break; // once found, break early
            }
        }
        return position;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // simple approach lgani ki index lena sabse pehle to preorder ka 
        // uski position find krni inorder me uske left wala aur right wala dekhna recursive call se 
        int preorderIndex = 0;
        TreeNode* ans = solve(preorder, inorder, preorderIndex, 0, inorder.size() - 1);
        return ans;
    }
};