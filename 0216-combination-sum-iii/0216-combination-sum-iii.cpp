class Solution {
    // more tricky than previous one k is no of element in given subset which may be 1<=k<=9 that make up the sum n here we treat n as a traget important to note 
    // each number in subset must be occour onces so candidates can be assume set of natural number upto 1 to 9

    private:
   void solve(int k,int n,vector<int>output,vector<vector<int>>&ans,int start){
        if(k==0 && n==0){
            //push krdo ans me 
            ans.push_back(output);
            return;
        }

        if((k>0 && n==0) || (k==0 && n>0)){
            //no valid combination exits 
            return;
        }


        //include 
        for(int i=start;i<=9;i++){

            // if number greate than sum
            if(i>n) break;



            output.push_back(i);
            solve(k-1,n-i,output,ans,i+1);
            output.pop_back();  //backtrack
        }
       
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>output;
        vector<vector<int>>ans;
        solve(k,n,output,ans,1);
        return ans;
    }
};