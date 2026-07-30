class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        //now initalizing that each student get one candy 
        vector<int>candies(n,1);
         int sum=0;


// left to right( comparing left neighbour with right neighbour)
        for( int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) {
                candies[i]=candies[i-1]+1;
            }
        }

        //right to left(comparing right neighbour to left neighbour)
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
       

       for(int i=0;i<candies.size();i++){
        sum+=candies[i];
       }
       return sum;
        
    }
};