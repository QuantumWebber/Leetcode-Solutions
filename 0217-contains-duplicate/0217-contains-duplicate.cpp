class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;

      for(int x:nums){
        if(map[x]>0) return true;
        map[x]++;
      }
      return false;
    
    }
};