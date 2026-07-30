class Solution {
public:
    int minBitFlips(int start, int goal) {


        int count=0;
       int xor_result=start^goal;

        while(xor_result){
            count+=xor_result & 1;
            xor_result>>=1;
        }
        return count;
        
    }
};