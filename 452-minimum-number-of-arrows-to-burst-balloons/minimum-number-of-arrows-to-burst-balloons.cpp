class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        long long arrowPos = points[0][1];   // pehla teer, pehle gubbare ke end pe

        for (int i = 1; i < (int)points.size(); i++) {
            if (points[i][0] > arrowPos) {
                // is gubbare tak teer nahi pahuchta — naya teer
                arrows++;
                arrowPos = points[i][1];
            } else {
                // isi teer se phoot jaayega, par range shrink karo
                arrowPos = min(arrowPos, (long long)points[i][1]);
            }
        }

        return arrows;
    }
};