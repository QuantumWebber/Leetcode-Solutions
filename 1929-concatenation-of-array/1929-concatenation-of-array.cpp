class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> copy=nums;
        nums.insert(nums.begin(),copy.begin(),copy.end());
        return nums;
    }
};