class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum=nums[0],sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }else{
                max_sum=max(sum,max_sum);
              sum=nums[i];
            }
        }
         return max(max_sum, sum); 
    }
};