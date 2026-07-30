class Solution {

    private:
    vector<int>prefixSum;

    int totalSum;

public:
    Solution(vector<int>& w) {
    int currentSum=0;

    for(int weight:w){
        currentSum+=weight;
        prefixSum.push_back(currentSum);

    }
    totalSum=currentSum;    
    }
    
    int pickIndex() {

        int target = (rand() % totalSum) + 1; // random target between 1 and totalSum


        int s=0;
        int e=prefixSum.size()-1;

        int ans=0;

        while(s<=e){
            int mid=s+(e-s)/2;

            if(prefixSum[mid]>=target){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }


        }

        return ans;
        
    }
};



// approach hai ki prefix sum se array bnwado usme randomly ek numbher chose kro uss domain mei phir binary search se uska index dhundke usse add krdo ans mei 

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */