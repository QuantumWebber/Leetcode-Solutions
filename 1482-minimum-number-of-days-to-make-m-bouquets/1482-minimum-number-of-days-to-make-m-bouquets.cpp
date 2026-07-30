class Solution {
private:
    // Helper function to check if it's possible to make m bouquets
    // with the given mid (number of days).
    bool ok(int mid, const vector<int>& bloomDay, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        
        // Traverse through the bloomDay array
        for (int i = 0; i < bloomDay.size(); i++) {
            // If the current flower can bloom within mid days
            if (bloomDay[i] <= mid) {
                flowers++; // Increment the consecutive flowers count
                // If we have enough flowers to make a bouquet
                if (flowers == k) {
                    bouquets++; // Make a bouquet
                    flowers = 0; // Reset the flowers count for the next bouquet
                }
            } else {
                flowers = 0; // Reset the flowers count if the current flower can't bloom
            }
        }
        
        // Return true if we can make at least m bouquets
        return bouquets >= m;
    }

public:
    // Function to find the minimum number of days required to make m bouquets
    int minDays(vector<int>& bloomDay, int m, int k) {
        // If it's impossible to make m bouquets, return -1
        if (static_cast<long long>(m) * k > bloomDay.size()) {
            return -1;
        }
        
        // Initialize the binary search bounds
        int s = 1;
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        
        // Binary search to find the minimum number of days
        while (s < e) {
            int mid = s + (e - s) / 2;
            // Check if it's possible to make m bouquets in mid days
            if (ok(mid, bloomDay, m, k)) {
                e = mid; // Try fewer days
            } else {
                s = mid + 1; // Try more days
            }
        }
        
        return s;
    }
};