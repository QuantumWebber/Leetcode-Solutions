class Solution {
private:
    int pivotElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1; // Pivot is in the right half
            } else if (nums[mid] < nums[high]) {
                high = mid; // Pivot is in the left half
            } else {
                // Handle duplicates: linearly search for the pivot
                if (nums[high - 1] > nums[high]) {
                    return high; // Pivot is at `high`
                }
                high--; // Reduce search space
            }
        }
        return low; // Pivot index
    }

    bool binarySearch(vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }

public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false; // Edge case: empty array

        int pivot = pivotElement(nums);

        // Search in both possible sorted halves
        return binarySearch(nums, pivot, n - 1, target) || binarySearch(nums, 0, pivot - 1, target);
    }
};