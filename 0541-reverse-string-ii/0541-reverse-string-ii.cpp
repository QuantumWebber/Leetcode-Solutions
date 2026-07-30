class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2 * k) {
            int j = i, m = min(i + k - 1, (int)s.length() - 1);
            while(j < m) {
                swap(s[j++], s[m--]);
            }
        }
        return s;
    }
};
