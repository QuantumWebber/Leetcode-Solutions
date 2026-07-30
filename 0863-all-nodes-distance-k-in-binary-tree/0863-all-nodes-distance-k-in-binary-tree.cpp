class Solution {

private:

    void makeParent(TreeNode* root,
    unordered_map<TreeNode*,TreeNode*>& parent){

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();

            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*> parent;

        makeParent(root,parent);

        unordered_map<TreeNode*,bool> visited;

        queue<TreeNode*> q;

        q.push(target);

        visited[target]=true;

        int currentLevel=0;

        while(!q.empty()){

            int size=q.size();

            if(currentLevel==k)
                break;

            for(int i=0;i<size;i++){

                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }

                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }

                if(parent[node] && !visited[parent[node]]){

                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }

            currentLevel++;
        }

        vector<int> ans;

        while(!q.empty()){

            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};