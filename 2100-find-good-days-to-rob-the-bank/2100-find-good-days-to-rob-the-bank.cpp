class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int k=security.size();
        vector<int> pre(k,0);
        vector<int> suf(k,0);
        vector<int>ans;
        for(int i=1;i<k;i++){
            //non increasing
            if(security[i-1]>=security[i]){
                pre[i]+=pre[i-1]+1;
            }
            //non decreasing
            if(security[k-1-i]<=security[k-i]){
                suf[k-1-i]+=suf[k-i]+1;
            }
        }
        for(int i=0;i<k;i++){
            if(pre[i]>=time && suf[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};