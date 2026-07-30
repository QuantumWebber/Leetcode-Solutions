class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,0);
        if(n==1) return nums[0];


        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            //take 
            int pick=dp[i-2]+nums[i];
            int notPick=dp[i-1];

            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};