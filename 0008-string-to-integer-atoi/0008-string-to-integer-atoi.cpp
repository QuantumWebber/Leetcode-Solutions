class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        // 1. Ignore leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle overflow
        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. Clamp to 32-bit range
            if (sign * num >= INT_MAX) return INT_MAX;
            if (sign * num <= INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
