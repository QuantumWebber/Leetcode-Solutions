class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeroCount = 0;
        long long subArr = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zeroCount++;
                subArr += zeroCount;
            }else{
                zeroCount = 0;
            }
        }


        return subArr;
    }
};