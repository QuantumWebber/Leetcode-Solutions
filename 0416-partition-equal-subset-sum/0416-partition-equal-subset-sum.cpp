class Solution {
private:
    vector<vector<int>> memo;
    
    bool solve(int i, int target, vector<int>& arr) {
        if (target == 0) return true;
        if (i == 0) return arr[0] == target;
        
        if (memo[i][target] != -1) return memo[i][target];
        
        bool notTake = solve(i - 1, target, arr);
        bool take = false;
        if (arr[i] <= target)
            take = solve(i - 1, target - arr[i], arr);
        
        return memo[i][target] = (take || notTake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;
        
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        
        memo.assign(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, nums);
    }
};