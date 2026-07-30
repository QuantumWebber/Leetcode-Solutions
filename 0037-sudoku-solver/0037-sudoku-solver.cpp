class Solution {
private:
    // Check if placing 'digit' at board[i][j] is valid
    bool safe(char digit, int i, int j, vector<vector<char>>& board) {
        for (int a = 0; a < 9; a++) {
            // check row and column
            if (board[i][a] == digit || board[a][j] == digit)
                return false;
        }

        // check 3x3 subgrid
       // Suppose i = 4, j = 7 → i.e., you're on row 4, column 7.


//startRow = 3 * (4 / 3) = 3 * 1 = 3
//startCol = 3 * (7 / 3) = 3 * 2 = 6




        int startRow = 3 * (i / 3);
        int startCol = 3 * (j / 3);
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[startRow + r][startCol + c] == digit)
                    return false;
            }
        }

        return true;
    }

    // Backtracking function to solve the board
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (safe(digit, i, j, board)) {
                            board[i][j] = digit;
                            if (solve(board)) return true; // continue if works
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid digit found
                }
            }
        }
        return true; // board is filled correctly
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
