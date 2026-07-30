class Solution {
   int count=0;
   int result=0;

   void inorder(TreeNode* &root, int k){
    if(root==nullptr) return;

    inorder(root->left,k);
    count++;

    if(count==k){
        result=root->val;
        return;
    }

    inorder(root->right,k);
   }
public:
    int kthSmallest(TreeNode* root, int k) {
        // we must apply inorder travseral because it return bst in sorted order and when it  reaches k return the value 

        //LNR
        inorder(root,k);
        return result;
    }
};
