class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // agr string empty to return " "
        string prefix = strs[0]; // prefix startring index
        for (string s : strs) 
            while (s.find(prefix) != 0) // agr prefix non zero aata to 
                prefix = prefix.substr(0, prefix.length() - 1);
        return prefix;
    }
};
