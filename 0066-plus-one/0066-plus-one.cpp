class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // Early return if no carry is needed
            } else {
                digits[i] = 0; // Set current digit to 0 and continue to the next digit
            }
        }
        
        // If we're here, it means all digits were 9s, so we need to add a new digit '1' at the beginning
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

