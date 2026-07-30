class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            // Count the occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            
            // Check if nums[i] is a majority element
            if (count > n / 3) {
                // Add to result only if it's not already included
                if (find(result.begin(), result.end(), nums[i]) == result.end()) {
                    result.push_back(nums[i]);
                }
            }
        }
        return result;
    }
};
