class Solution {

    private:
    int pivotElement(vector<int>&nums){
        int s=0,e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]) s=mid+1;
            else e=mid;
        }
        return s;




    }




    int binarySearch(vector<int>& arr, int s, int e, int target) { // Fixed parameter list
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1; // Not found
    }


public:
    int search(vector<int>& nums, int target) {

        // step-1: Find Pivot Element 

        int pivot=pivotElement(nums);
        int n=nums.size();

        if(nums[pivot]<=target  && target<=nums[n-1]){
            return binarySearch(nums,pivot,n-1,target);
        }else{
            return binarySearch(nums,0,pivot,target);
        }

        
        
    }
};