class Solution {
    // problem is niklne subset hi hai but n jo hai uss range se candiate array bnanna 

    // example n=4 
    //[1,2,3,4,5]
    //k ke possible combination [1,2] [2,3] [3,4],[4,5],[1,3],[1,4]

    private:
    void solve(int n, int k, vector<int>& output, vector<vector<int>>& ans, int start) {
        if (k == 0) {  // If k elements are selected
            ans.push_back(output);
            return;
        }

        if (k > n - start + 1) return; // Prune recursion if not enough elements left

        // Loop to choose numbers one by one
        for (int i = start; i <= n; i++) {
            output.push_back(i);
            solve(n, k - 1, output, ans, i + 1);
            output.pop_back();  // Backtrack
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(n, k, output, ans, 1);
        return ans;
    }
};
