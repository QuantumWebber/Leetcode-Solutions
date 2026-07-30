class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
                vector<int> ans;
        int rows=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int total=rows*col;

        int starting_row=0;
        int starting_col=0;
        int ending_row=rows-1;
        int ending_col=col-1;


        while(count<total){
            //starting row 
            for(int i=starting_col;count<total && i<=ending_col;i++){
                ans.push_back(matrix[starting_row][i]);
                count++;
            }
            starting_row++;
 // Ending column
            for (int i = starting_row; count < total && i <= ending_row; i++) {
                ans.push_back(matrix[i][ending_col]);
                count++;
            }
            ending_col--;
            // Ending row
            for (int i = ending_col; count < total && i >= starting_col; i--) {
                ans.push_back(matrix[ending_row][i]);
                count++;
            }
            ending_row--;
            // Starting column
            for (int i = ending_row; count < total && i >= starting_row; i--) {
                ans.push_back(matrix[i][starting_col]);
                count++;
            }
            starting_col++;
        }
        return ans;
    }
};
