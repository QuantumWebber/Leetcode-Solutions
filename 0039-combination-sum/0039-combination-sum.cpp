class Solution {

    private:
    void solve(vector<int>& candidates, int target, int index, vector<int> output, vector<vector<int>>& ans){

        //Base case
        if(index>=candidates.size()){

            return;
        }

            if(target==0){
                ans.push_back(output);
                return;
            }
        

            if(target<0){
                return;
            }
        

        //include
        output.push_back(candidates[index]);
        solve(candidates,target-candidates[index],index,output,ans);


        //Exclude
        //backprogation-to watch for other options

        output.pop_back();

        solve(candidates,target,index+1,output,ans);



    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        // combination sum - yha index ko badhna bhi nhi kyoki wo bhi multiple times use ho sakta hai 

        vector<int>output;
        vector<vector<int>>ans;
        int index=0;


        solve(candidates,target,index,output,ans);
        return ans ;


        



        
    }
};