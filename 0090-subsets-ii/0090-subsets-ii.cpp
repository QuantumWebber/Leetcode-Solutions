class Solution {
private:
    void solve(vector<int>& nums,
               vector<int>& ans,
               int start,
               vector<vector<int>>& output) {

        output.push_back(ans);

        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i - 1])
                continue;

            ans.push_back(nums[i]);

            solve(nums, ans, i + 1, output);

            ans.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> output;
        vector<int> ans;

        solve(nums, ans, 0, output);

        return output;
    }
};