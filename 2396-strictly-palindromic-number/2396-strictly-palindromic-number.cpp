class Solution {
private:
  
    bool isBasePalindrome(int n, int base) {
        long long num = n;
        long long rev = 0;
        while (num > 0) {
            int rem = num % base;
            rev = rev * base + rem;
            num /= base;
        }
        return n == rev;
    }

public:
    bool isStrictlyPalindromic(int n) {
        // Check for each base from 2 to n-2
        for (int base = 2; base <= n - 2; base++) {
            if (!isBasePalindrome(n, base)) {
                return false;
            }
        }
        return true;
    }
};