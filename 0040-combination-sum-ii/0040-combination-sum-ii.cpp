class Solution {
    // iss combination or purane wale me difference ye yha pr ek number ek hi baar use ho sakta 

    void solve(vector<int>& candidates, int target, vector<int> output,
               int index, vector<vector<int>>& ans) {  // Pass ans by reference

        /// boundary case handle krle yr
        if (target == 0) {  // Ensure only valid subsets are pushed
            ans.push_back(output);
            return;
        }

        if (target < 0 || index >= candidates.size()) {  // No need to check index separately later
            // target hi negative to aage kyu badhna 
            return;
        }

        // include 
        // firstly ignore duplicate 
        for (int i = index; i < candidates.size(); i++) {  // Start from 'index' to prevent reusing elements
            if (i > index && candidates[i] == candidates[i - 1]) { // Skip duplicates
                continue;
            }

            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], output, i + 1, ans); // Move to next index
            output.pop_back();  // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());  // Sorting to handle duplicates
        int index = 0;
        solve(candidates, target, output, index, ans);
        return ans;
    }
};
