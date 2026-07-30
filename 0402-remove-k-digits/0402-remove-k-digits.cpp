class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (auto c : num) {
            while (k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                k--;
            }
            if (!st.empty() || c != '0') {
                st.push(c);  // Avoid leading zeros
            }
        }

        // Remove remaining digits from the end if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Construct the final result
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Edge case for an empty result
        return result.empty() ? "0" : result;
    }
};
