class Solution {
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;

        for (int nbr = 0; nbr < isConnected.size(); nbr++) {
            if (isConnected[node][nbr] == 1 && !vis[nbr]) {
                dfs(nbr, isConnected, vis);   // <-- yahi mistake thi
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<int> vis(n, 0);

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};