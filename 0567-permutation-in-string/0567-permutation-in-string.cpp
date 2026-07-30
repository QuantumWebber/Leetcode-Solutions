class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char,int> need;

// Build frequency
for(char ch:s1)
    need[ch]++;

int required=s1.length();
int l=0;

for(int r=0;r<s2.length();r++){

    // Expand
    if(need[s2[r]]>0)
        required--;

    need[s2[r]]--;

    // Maintain fixed window
    if(r-l+1>s1.length()){

        need[s2[l]]++;

        if(need[s2[l]]>0)
            required++;

        l++;
    }

    // Found permutation
    if(required==0)
        return true;
}

return false;
        
    }
};