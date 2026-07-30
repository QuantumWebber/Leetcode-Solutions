class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int s=0, e=n-1;
        vector<int>ans(n);
        for(int num:nums){
            if(num<pivot){
                ans[s++]=num;
            }
        }

          for(int num:nums){
            if(num==pivot){
                ans[s++]=num;
            }
        }

          for(int num:nums){
            if(num>pivot){
                ans[s++]=num;
            }
        }
        return ans;
    }
};