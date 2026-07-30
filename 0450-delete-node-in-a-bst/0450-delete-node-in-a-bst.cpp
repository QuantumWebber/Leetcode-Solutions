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
    
   int minVal(TreeNode* root){
    TreeNode* temp = root;

    while(temp->left != nullptr){
        temp = temp->left;
    }

    return temp->val;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {


        // dekho root hai aur wo key hai jo delete krni hai 
        

        if(root==nullptr)   return nullptr;

        if(root->val==key){


            // if no child 

            if(root->left==nullptr && root->right==nullptr){
                delete root;
                return nullptr;
            }


            // if having one child ie in lefty

            if(root->left!=nullptr  && root->right==nullptr){
                TreeNode* temp=root->left;

                delete root;
                return temp;
            }



            // one child right 
             if(root->left==nullptr  && root->right!=nullptr){
                TreeNode* temp=root->right;

                delete root;
                return temp;
            }

            // two child 

             if(root->left!=nullptr  && root->right!=nullptr){
                int mini=minVal(root->right);

                root->val=mini;
                root->right=deleteNode(root->right,mini);
            }
        }else if ( root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};