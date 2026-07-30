class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twoes=0;
        for(int num:nums){
        ones=(ones ^ num) & ~twoes;
        twoes=(twoes ^ num ) & ~ones;

        }
        return ones;
    }
};