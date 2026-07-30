class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long  count=0;
         if (k <= 1) return 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long curr_pro=1;
            for(int j=i;j<n;j++){
                curr_pro*=nums[j];
                if(curr_pro>=k){
                    break;
                }else{
                    count++;
                }
            }
        }
        return count;
    }
};