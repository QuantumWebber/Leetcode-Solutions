class Solution {
private:
    // Finding rightmost occurrence
    int rightOcurrance(vector<int>& arr, int target) { 
        int s = 0, e = arr.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] <= target) { 
                if (arr[mid] == target) {
                    ans = mid; 
                }
                s = mid + 1; 
            } else { 
                e = mid - 1;
            }
        }
        return ans; 
    }

    // Finding leftmost occurrence
    int leftOcurrance(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] >= target) { 
                if (arr[mid] == target) {
                    ans = mid; 
                }
                e = mid - 1; 
            } else { 
                s = mid + 1; 
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftOcurrance(nums, target); 
        int right = rightOcurrance(nums, target); 

        if (left == -1 || right == -1) { 
            return {-1, -1}; 
        }

        return {left, right}; 
    }
};