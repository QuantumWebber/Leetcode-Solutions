class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int even=0, odd=1; // positive even negative odd 
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[even]=nums[i];
                even+=2;
            }else{
                ans[odd]=nums[i];
                odd+=2;
            }
        }
        return ans;
    }
};