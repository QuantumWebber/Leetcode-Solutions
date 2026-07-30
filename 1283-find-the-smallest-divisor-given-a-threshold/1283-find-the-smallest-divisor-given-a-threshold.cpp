class Solution {
public:
int sumHelper(vector<int>&nums,int divisor){
    int sum=0;
    for(int i=0;i<nums.size();i++){
      sum+=(nums[i]+divisor-1)/ divisor;
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
       int s=1;
       int e= *max_element(nums.begin(), nums.end());
       while(s<e){
        int mid=s+(e-s)/2;
        int sum=sumHelper(nums,mid);
        
        if(sum>threshold){
            s=mid+1;
        }else{
            e=mid;
        }
       
       }
       return s;
    }
};