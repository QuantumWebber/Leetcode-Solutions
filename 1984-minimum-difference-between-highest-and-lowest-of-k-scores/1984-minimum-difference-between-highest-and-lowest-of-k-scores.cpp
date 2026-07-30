class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0; // If k=1, min difference is 0 (single element)
        
        sort(nums.begin(), nums.end()); // Sort the array

        int minDiff = INT_MAX;
        for (int i = 0; i <= nums.size() - k; i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]); // Compare differences
        }

        return minDiff;
    }
};
