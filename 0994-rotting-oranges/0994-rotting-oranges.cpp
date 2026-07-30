class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();



        queue<pair<int,int>>q; // row and col of rotten orange store kroge 

        int freshCount=0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    freshCount++;
                
            }
        }
    }


    int minutes=0;

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};

    while(!q.empty()){

    int size=q.size();
    bool rottenFound=false;

    for(int i=0;i<size;i++){

        auto [r,c]=q.front();
        q.pop();

        for(int d=0;d<4;d++){

            int nr=r+dr[d];
            int nc=c+dc[d];

            if(nr>=0 && nr<rows &&
               nc>=0 && nc<cols &&
               grid[nr][nc]==1){

                grid[nr][nc]=2;
                freshCount--;

                q.push({nr,nc});
                rottenFound=true;
            }
        }
    }

    if(rottenFound)
        minutes++;
}

if(freshCount>0)
    return -1;

return minutes;
    }
};