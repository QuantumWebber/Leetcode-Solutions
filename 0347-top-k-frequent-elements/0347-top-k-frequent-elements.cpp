class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
    unordered_map<int,int>freq;

        for(int num:nums){
            freq[num]++;
        }

        // yha maine haar ek element ki frequency ko count krlia hai 


        // now second step i will use bucket sort but yha bucket ke index mei freq count ke hissab se bnayuga 
        int n=nums.size();
        vector<vector<int>>bucket(n+1);

        //fill the bucket on basis on frequency 
       for(auto &it:freq){
        int num=it.first;
        int f=it.second;
        bucket[f].push_back(num);
       } 

      vector<int>ans;
      for(int i=n;i>=0;i--){
        for(int num:bucket[i]){
            ans.push_back(num);

            if(ans.size()==k)  return ans;
           
        }
      }


return ans;


    }
};