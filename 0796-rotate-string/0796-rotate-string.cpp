class Solution {
    private:
    void rotate(string &s) {
        int n = s.length();
        if (n == 0) return;
        char first = s[0];
        for (int i = 0; i < n - 1; ++i) {
            s[i] = s[i + 1];
        }
        s[n - 1] = first;
    }

public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            rotate(s);
            if (s == goal) {
                return true;
            }
        }

        return false;
    }
};
