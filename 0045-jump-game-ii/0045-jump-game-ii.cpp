class Solution {
public:
    int jump(vector<int>& nums) {
        // here nums[i] tell maximum no of step you can take to jump tp rach the final destination 
        int n=nums.size();
        int maxReach=0;
        int count=0;
        int lastEnd=0;

        for(int i=0;i<n-1;i++){
            maxReach=max(maxReach,nums[i]+i);
            if(i==lastEnd){
                count++;
                lastEnd=maxReach;
            }
        }
        return count;
    }
};