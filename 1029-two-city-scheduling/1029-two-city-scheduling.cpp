class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        

        //sorting pehle case mei on the basis of difference jitna negative zada hoga utna hi city a ke liye fiyada hoga 

        sort(costs.begin(), costs.end(),[](const vector<int>& a, vector<int>& b){
            return (a[0]-a[1])<(b[0]-b[1]);
        });


        int total=0;
        for(int i=0;i<costs.size()/2;i++){
            total+=costs[i][0];
        }

         for(int i=costs.size()/2;i<costs.size();i++){
            total+=costs[i][1];
        }

        return total;
    }
};