class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        


        int l=0; 
        int ans=0;
        unordered_set<char>st;


        for(int r=0;r<s.length(); r++){
            // expand

            while(st.count(s[r])){
                // shrink to make window valid 

                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);

            // record
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};