class Solution {
public:
    int hammingWeight(int n) {
        


        // i need to calulate set bits 
        int count=0;
        while(n!=0){
            count=count+(n&1);
           n= n>>1;
        }
        return count;
    }
};