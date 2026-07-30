class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0, mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curr++;
            }else{
                mx=max(mx,curr);
                curr=0;
            }
        }
        return max(curr,mx);
    }
};