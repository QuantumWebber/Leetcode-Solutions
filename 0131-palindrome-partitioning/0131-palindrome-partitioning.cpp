class Solution {

private:

    bool isPalindrome(string &s, int start, int end) {

        while (start < end) {

            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void solve(string &s,
               vector<vector<string>> &ans,
               int start,
               vector<string> &temp) {

        // Base Case
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible partition
        for (int end = start; end < s.size(); end++) {

            // Choose only if palindrome
            if (isPalindrome(s, start, end)) {

                temp.push_back(s.substr(start, end - start + 1));

                solve(s, ans, end + 1, temp);

                // Backtrack
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, 0, temp);

        return ans;
    }
};