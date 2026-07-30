class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        

        // beautiful question very very beautiful question 

       long long xor_total=0;
        for(int i=0;i<nums.size();i++){
          xor_total^=nums[i];
        }



        long long mask = xor_total & (-xor_total); // ek no aur uske 2s compliment ka and to sirf ek 1 aayega 

        int x=0;
        int y=0;

        for(int num:nums){

             // yani ek no jispr 1 mask ki position pr aata hai 
            if((num & mask)!=0){
                x^=num;
            }else{
                y^=num;
            }
        }
        return {x,y};
    }
};