class Solution {
    private:
     int robi(vector<int>& nums,int start,int end) {
        int n=end-start+1;

        vector<int>dp(n,0);
        if(n==1) return nums[start];


        dp[0]=nums[start];
        dp[1]=max(nums[start],nums[start+1]);

        for(int i=2;i<n;i++){
            //take 
            int pick=dp[i-2]+nums[i+start];
            int notPick=dp[i-1];

            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        //case 1: include house 0 exlude n-1
        int caseA=robi(nums,0,n-2);

        int caseB=robi(nums,1,n-1);

        return max(caseA,caseB);
        
        
    }
};