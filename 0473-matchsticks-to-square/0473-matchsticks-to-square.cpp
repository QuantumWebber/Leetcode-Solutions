class Solution {

    private:

    bool solve(vector<int>& matchsticks,vector<int>& side, int target, int index){

        if(index==matchsticks.size()){
            return side[0]==target && side[1]==target && side[2]==target && side[3]==target;
        }


        for(int i=0;i<4;i++){

            if(side[i]+matchsticks[index]>target) continue;


            side[i]+=matchsticks[index];


            if(solve(matchsticks,side,target,index+1))  return true;


            side[i]-=matchsticks[index];


          
        }
          return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        
         int sum = 0;

        for(int x : matchsticks)
            sum += x;

        if(sum % 4 != 0)
            return false;



        int target = sum / 4;
         sort(matchsticks.rbegin(),
             matchsticks.rend());
vector<int> side(4, 0);

        return solve(matchsticks,
                     side,
                     target,
                     0);


    }
};