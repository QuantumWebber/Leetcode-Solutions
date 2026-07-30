class Solution {
public:
    int maxPower(string s) {
        int curr=1, mx=1;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                curr++;
            }else{
                mx=max(mx,curr);
                curr=1;
            }

        }
        return max(mx,curr);
    }
};