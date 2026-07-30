class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        // dekho jee hai to sliding window hi na wo bhi fixed length wali apni variety 1 
  
    long long target=threshold*(long long)k;

    long long sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

   int ans=(sum>=target);

   for(int r=k;r<arr.size();r++){
    sum+=arr[r];
    sum-=arr[r-k];

    if(sum>=target) ans++;
   }



return ans;

    }
};