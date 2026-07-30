class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // Max Heap: {distance, point}
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto point : points) {

            int x = point[0];
            int y = point[1];

            // Mistake fixed: declare distance
            int distance = x * x + y * y;

            // Mistake fixed: use maxHeap instead of pq
            maxHeap.push({distance, point});

            // Keep only k closest points
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> result;

        // Mistake fixed: pop elements while extracting
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};