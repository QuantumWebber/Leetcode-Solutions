class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += mat[i][i]; // Primary diagonal
            if (i != n - i - 1) { // Secondary diagonal, avoid double counting the center element in odd-dimension matrices
                sum += mat[i][n - i - 1];
            }
        }
        
        return sum;
    }
};
