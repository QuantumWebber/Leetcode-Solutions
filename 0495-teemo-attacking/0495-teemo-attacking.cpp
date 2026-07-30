class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0; 

        int totalDuration = 0;
        int n = timeSeries.size();

        for (int i = 0; i < n - 1; i++) {
            
            totalDuration += min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        
        totalDuration += duration;

        return totalDuration;
    }
};
