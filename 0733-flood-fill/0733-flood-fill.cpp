class Solution {
public:

    void dfs(int row, int col,
             vector<vector<int>>& image,
             int original,
             int color) {

        int n = image.size();
        int m = image[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m)
            return;

        // Different color
        if(image[row][col] != original)
            return;

        // Paint
        image[row][col] = color;

        dfs(row-1, col, image, original, color);
        dfs(row+1, col, image, original, color);
        dfs(row, col-1, image, original, color);
        dfs(row, col+1, image, original, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        int original = image[sr][sc];

        if(original == color)
            return image;

        dfs(sr, sc, image, original, color);

        return image;
    }
};