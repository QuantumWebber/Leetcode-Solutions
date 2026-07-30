class Solution {
    private:
    int hammingWeight(int n) {
        


        // i need to calulate set bits 
        int count=0;
        while(n!=0){
            count=count+(n&1);
           n= n>>1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
       vector<int> ans(n + 1, 0);
       
        for(int i=0;i<=n;i++){
           ans[i]=hammingWeight(i);
        }
        return ans;
        
    }
};