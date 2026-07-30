class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        int i = 0;
        while (i < n) {
            string temp;
            // Skip leading spaces
            while (i < n && s[i] == ' ') {
                i++;
            }
            // Collect characters of the current word
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            // Add the word to the result
            if (!temp.empty()) {
                if (ans.empty()) {
                    ans = temp;
                } else {
                    ans = temp + " " + ans;
                }
            }
        }
        return ans;
    }
};