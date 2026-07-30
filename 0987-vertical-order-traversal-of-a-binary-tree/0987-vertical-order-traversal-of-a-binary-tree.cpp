class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        if (!root) return {};
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].insert(frontNode->val);

            if (frontNode->left) {
                q.push({frontNode->left, {hd - 1, lvl + 1}});
            }

            if (frontNode->right) {
                q.push({frontNode->right, {hd + 1, lvl + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};