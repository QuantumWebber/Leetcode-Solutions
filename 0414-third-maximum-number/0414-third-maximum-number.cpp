class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Sort the vector in ascending order
        sort(nums.begin(), nums.end());

        // Initialize a count of distinct maximum numbers found
        int count = 1;  // Start with the largest element
        int i = nums.size() - 1; // Start from the last element (largest)

        // Iterate backward through the sorted vector
        for (; i > 0; i--) {
            if (nums[i] != nums[i - 1]) {
                count++;
            }
            // If we have found the third distinct maximum
            if (count == 3) {
                return nums[i - 1];
            }
        }

        // If there are fewer than 3 distinct numbers, return the maximum
        return nums[nums.size() - 1];
    }
};