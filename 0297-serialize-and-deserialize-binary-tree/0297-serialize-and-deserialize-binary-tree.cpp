/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize Helper
    void solve(TreeNode* root, string &ans) {
        if (root == NULL) {
            ans += "N,";
            return;
        }

        ans += to_string(root->val) + ",";
        solve(root->left, ans);
        solve(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        solve(root, ans);
        return ans;
    }

    // Deserialize Helper
    TreeNode* build(vector<string> &nodes, int &index) {
        if (index >= nodes.size() || nodes[index] == "N") {
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = build(nodes, index);
        root->right = build(nodes, index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string temp = "";

        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        int index = 0;
        return build(nodes, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));