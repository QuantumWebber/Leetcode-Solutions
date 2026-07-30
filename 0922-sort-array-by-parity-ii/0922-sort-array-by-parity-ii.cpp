class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even=0, odd=1;
        int n=nums.size();
        vector<int>ans(n);

        for(int num:nums){
            if(num%2==0){
                ans[even]=num;
                even+=2;
            }else{
                ans[odd]=num;
                odd+=2;
            }
        }
        return ans;
    }
};