class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int count=0;
        vector<int>result;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
              count++;
              result.push_back(nums[i]);
              count=0;
            } else{
                count=0;
            }
        }
        return result;
    }
};