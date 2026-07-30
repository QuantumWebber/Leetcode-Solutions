class Solution {
public:
    vector<int> grayCode(int n){

        // base case(s)
        if(n == 1){
            return {0,1};
        }

        // recursive case(s)
        
        // get the grayCode for n-1
        vector<int> temp = grayCode(n-1);
        int m = temp.size();

        // now using the temp vector having gray code for n-1 we will construct the gray code for n
        vector<int> ans;
        // the first half of the 2^(n-1) elements of gray code for n will have 0 before the MSB of graycodes of n-1 which is same as all graycodes of n-1
        for(int num : temp){
            ans.push_back(num);
        }
        // the next half of the 2^(n-1) elements of gray code for n will have 1 before the MSB of graycodes of n-1 but in reverse order
        for(int i=m-1; i>=0; i--){
            int newGrayCode = (temp[i] | (1 << (n-1)));
            ans.push_back(newGrayCode);
        }

        return ans;
    }
};