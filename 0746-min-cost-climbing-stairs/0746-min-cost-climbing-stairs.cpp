class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

    
        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {

            
            int oneStepCost = dp[i-1] + cost[i];

            
            int twoStepCost = dp[i-2] + cost[i];

            dp[i] = min(oneStepCost, twoStepCost);
        }

        return min(dp[n-1], dp[n-2]);
    }
};