class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        // Total sum nikalo
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Hume middle me itna sum bachana hai
        int target = total - x;

        // Agar target negative hai to impossible
        if (target < 0)
            return -1;

        // Agar target 0 hai to poora array remove karna padega
        if (target == 0)
            return nums.size();

        int l = 0;
        int sum = 0;
        int longest = -1;

        // Longest subarray with sum = target
        for (int r = 0; r < nums.size(); r++) {

            // Expand window
            sum += nums[r];

            // Sum bada ho gaya to shrink karo
            while (sum > target) {
                sum -= nums[l];
                l++;
            }

            // Agar target mil gaya
            if (sum == target) {
                longest = max(longest, r - l + 1);
            }
        }

        // Agar koi subarray hi nahi mili
        if (longest == -1)
            return -1;

        // Remaining elements remove karne padenge
        return nums.size() - longest;
    }
};