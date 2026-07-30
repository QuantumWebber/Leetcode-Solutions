class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int candidate = -1, count = 0;

        // First Pass: Find the candidate using Boyer-Moore
        for (int num : nums) {
            if (num % 2 == 0) { // Only consider even numbers
                if (num == candidate) {
                    count++;
                } else if (count == 0) {
                    candidate = num;
                    count = 1;
                } else {
                    count--;
                }
            }
        }

        // Second Pass: Validate the candidate
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        // Check if there are other even numbers with the same frequency
        int maxFreq = count;
        for (int num : nums) {
            if (num % 2 == 0 && num != candidate) {
                int freq = 0;
                for (int x : nums) {
                    if (x == num) freq++;
                }
                if (freq > maxFreq || (freq == maxFreq && num < candidate)) {
                    candidate = num;
                    maxFreq = freq;
                }
            }
        }

        return maxFreq > 0 ? candidate : -1;
    }
};
