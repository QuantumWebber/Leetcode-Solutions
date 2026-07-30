class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sort the array to ensure the window can be adjusted to make all elements equal
        sort(nums.begin(), nums.end());
        
        // Initialize pointers for the sliding window technique
        int left = 0, right = 0;
        
        // Variables to store the result and the sum of the current window
        long res = 0, total = 0;
        
        // Iterate through the array
        while (right < nums.size()) {
            // Add the current element to the total sum of the window
            total += nums[right];
            
            // Check if the current window is valid, i.e., 
            // can we make all elements in the window equal to nums[right] with at most 'k' operations?
            // The condition is: nums[right] * window_size <= total + k
            while ((long)nums[right] * (right - left + 1) > total + k) {
                // If not valid, shrink the window from the left
                total -= nums[left];
                left += 1;
            }
            
            // Update the result with the maximum size of the valid window
            res = max(res, (long)(right - left + 1));
            
            // Expand the window to the right
            right += 1;
        }
        
       
        return res;
    }
};
