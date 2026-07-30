class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> result;
        int maxCandies = getMaxCandies(candies); // Get the maximum candies currently possessed
        
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
    
private:
    int getMaxCandies(std::vector<int>& candies) {
        int maxCandies = candies[0];
        for (int i = 1; i < candies.size(); ++i) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }
        return maxCandies;
    }
};

