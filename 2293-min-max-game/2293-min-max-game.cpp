class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        while(n>1){
        for(int i=0;i<n/2;i++){
           if (i % 2 == 0) {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]); // Minimum for even indices
                } else {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]); // Maximum for odd indices
                }

        }
      n--;
      
        }
        
        return nums[0];
    }
};