class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum=0;
        int l=0;
        int best=INT_MAX;


        for(int r=0;r<nums.size();r++){
              sum+=nums[r];


              while(sum>=target){
                best=min(best,r-l+1);
                sum-=nums[l];
                l++;
              }


        }
       return  best==INT_MAX?0:best;
    }
};