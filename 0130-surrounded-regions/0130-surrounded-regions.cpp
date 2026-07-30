class Solution {

    //Boundary se connected O ko bachana hai.
//Jo O boundary tak nahi pahunch sakte (completely surrounded by X) unhe X me convert karna hai.


//Boundary ke saare O par DFS chalao.
//DFS se jitne connected O hain unhe temporary 'S' (Safe) mark kar do.
//Puri matrix traverse karo:
//'O' → 'X' (captured region)
//'S' → 'O' (restore safe region)


    void dfs(int row, int col, vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m)
            return;

        if(board[row][col] != 'O')
            return;

        // Mark as Safe
        board[row][col] = 'S';

        dfs(row - 1, col, board);
        dfs(row + 1, col, board);
        dfs(row, col - 1, board);
        dfs(row, col + 1, board);
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // First Row
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O')
                dfs(0, j, board);
        }

        // Last Row
        for(int j = 0; j < m; j++) {
            if(board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }

        // First Column
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O')
                dfs(i, 0, board);
        }

        // Last Column
        for(int i = 0; i < n; i++) {
            if(board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }

        // Convert captured regions and restore safe regions
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};