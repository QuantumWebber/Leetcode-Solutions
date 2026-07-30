class Solution {
public:
    int maxProduct(vector<int>& nums) {
        

        // approcah is kadane algrithm only 
        
        int minProd=nums[0];
        int maxProd=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
             int curr=nums[i];

             if(curr<0){
                swap(minProd,maxProd);
             }

             maxProd=max(curr,maxProd*curr);
             minProd=min(curr,minProd*curr);
             ans=max(ans,maxProd);
        }
        return ans;
        
    }
};