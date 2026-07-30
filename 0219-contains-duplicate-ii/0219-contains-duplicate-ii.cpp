class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n=nums.size();

        unordered_set<int>window;

        for(int i=0;i<n;i++){


            // if element out of winodw hai usese nikl do 
            if(i>k) window.erase(nums[i-k-1]);

            // agr already window mei to bas trur 
            if(window.count(nums[i])) return true;


            // vrna insert
            window.insert(nums[i]);
        }
        return false;
    }
};