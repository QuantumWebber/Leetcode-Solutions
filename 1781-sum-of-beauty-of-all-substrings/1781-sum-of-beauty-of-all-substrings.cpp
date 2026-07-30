class Solution {
public:
int ans=0;
    int beautySum(string s) {
        for(int i=0;i<s.length();i++){
            map<char,int>mp;
            // count freq of each element
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;

                int leastFreq=INT_MAX;
                int mostFreq=INT_MIN;
                for(auto it:mp){
                    leastFreq=min(leastFreq,it.second);
                    mostFreq=max(mostFreq,it.second);
                }
                  ans+=mostFreq-leastFreq;

            }
        }
        return ans;
    }
};