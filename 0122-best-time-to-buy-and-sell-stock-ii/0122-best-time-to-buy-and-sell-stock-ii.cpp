class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
       int buy=prices[0];
       for (auto i:prices){
        if(i<buy) buy=i;
        else{
       profit+=i-buy;
       buy=i;
       }
       }
       return profit;
    }
};