class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int index = 0, num = 1;
        
        // Find missing numbers until we collect k missing numbers
        while (missing.size() < k) {
            if (index < arr.size() && arr[index] == num) {
                // If num is present in arr, move to the next index
                index++;
            } else {
                // If num is missing, store it
                missing.push_back(num);
            }
            num++;
        }
        
        return missing[k - 1];  // k-th missing element (1-based indexing)
    }
};