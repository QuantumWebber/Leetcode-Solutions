class Solution {
    private:
    vector<int>arr;
public:
    Solution(vector<int>& nums):arr(nums) {
        
    }
    
    int pick(int target) {
        int ans=-1;
        int count=0; // to count target 



        for(int i=0;i<arr.size();i++){
            if(arr[i]!=target){
                continue;
            }

            count++;


            if(rand() % count==0)  ans=i;
            //naya index temp ans bn agaya 
            // 0 aane ki prob 1/count hogi 

        }
        return ans ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */