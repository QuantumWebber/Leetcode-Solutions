class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // Sort according to pickup location
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // {dropLocation, passengers}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        int currentPassengers = 0;

        for (auto &trip : trips) {

            int passengers = trip[0];
            int pickupLocation = trip[1];
            int dropLocation = trip[2];

            // Remove all passengers who have already reached destination
            while (!minHeap.empty() && minHeap.top().first <= pickupLocation) {

                // subtract passengers, NOT drop location
                currentPassengers -= minHeap.top().second;
                minHeap.pop();
            }

            // Pick up current passengers
            currentPassengers += passengers;

            // Capacity exceeded
            if (currentPassengers > capacity)
                return false;

            // Store when these passengers will leave
            minHeap.push({dropLocation, passengers});
        }

        return true;
    }
};