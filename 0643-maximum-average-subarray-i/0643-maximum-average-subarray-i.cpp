class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        long long best=sum;
        for(int r=k;r<nums.size();r++){
            sum+=nums[r];
            sum-=nums[r-k];
            best=max(best,sum);
        }
        return (double) best/k;
    }
};