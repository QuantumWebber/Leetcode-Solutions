class Solution {
    
public:


void dfs(int row,int col,vector<vector<char>>&grid){
    int m=grid.size();
    int n=grid[0].size();


    if(row<0 || col<0 || row>=m || col>=n){
        return;
    }


    if(grid[row][col]=='0') return;

    // Mark as visited
        grid[row][col] = '0';


        dfs(row-1,col,grid);
        dfs(row+1,col,grid);
        dfs(row,col-1,grid);
        dfs(row,col+1,grid);


}
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();


        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++ ){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid); //visit complete island
                }


            }
        }
        return count;
    }
};