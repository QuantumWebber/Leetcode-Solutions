class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // pehla interval daal do
        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){

            // last interval ko reference se lo (IMPORTANT)
            vector<int>& lastAddedInterval = result.back();

            // overlap check
            if(lastAddedInterval[1] >= intervals[i][0]){

                // merge karo
                lastAddedInterval[1] = max(lastAddedInterval[1], intervals[i][1]);

            } else {

                // naya interval add karo
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};