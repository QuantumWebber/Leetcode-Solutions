class Solution {
public:

    int n, m;

    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        
        if(dp[r][c] != -1)
            return dp[r][c];

       
        int ans = 1;

        
        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            // Boundary check
            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {

                // Sirf larger value pe ja sakte hain
                if(matrix[nr][nc] > matrix[r][c]) {

                    ans = max(ans,
                              1 + dfs(nr, nc, matrix, dp));
                }
            }
        }

        // Memoize
        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();

        // DP initialized with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int longest = 0;

        // Har cell se DFS chalao
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                longest = max(longest,
                              dfs(i, j, matrix, dp));
            }
        }

        return longest;
    }
};