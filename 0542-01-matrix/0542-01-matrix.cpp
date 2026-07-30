class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> dist(r, vector<int>(c, -1));
        queue<pair<int, int>> q;

        // Push all 0's into queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            for (int d = 0; d < 4; d++) {

                int nr = row + dr[d];
                int nc = col + dc[d];

                if (nr >= 0 && nr < r &&
                    nc >= 0 && nc < c &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};