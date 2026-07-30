class Solution {
private:
    bool ok(int mid, vector<int>& weights, int days) {
        int dayCount = 1;  // Start from day 1
        int currWeight = 0;  

        for (int weight : weights) {
            if (currWeight + weight > mid) {  
                // Exceeded capacity, start a new day
                dayCount++;
                currWeight = 0;  
            }
            currWeight += weight;  
            
            if (dayCount > days) return false;  // Too many days needed
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());  // Minimum capacity must be max(weights)
        int e = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity is sum(weights)

        while (s < e) {
            int mid = s + (e - s) / 2;
            if (ok(mid, weights, days)) {
                e = mid;  // Try a smaller capacity
            } else {
                s = mid + 1;  // Increase the capacity
            }
        }
        return s;
    }
};
