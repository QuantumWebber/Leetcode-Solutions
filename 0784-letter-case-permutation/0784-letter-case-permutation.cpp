

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<int> letterIndices;
        int n = s.size();
        
        // Step 1: Identify positions of all alphabetic characters
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                letterIndices.push_back(i);
            }
        }
        
        int numLetters = letterIndices.size();
        int totalPermutations = 1 << numLetters; // 2^numLetters
        vector<string> result;

        // Step 2: Generate all permutations using bit manipulation
        for (int mask = 0; mask < totalPermutations; mask++) {
            string temp = s;
            for (int j = 0; j < numLetters; j++) {
                int index = letterIndices[j];
                // Check if the j-th bit in the mask is set
                if (mask & (1 << j)) {
                    // Toggle the case of the letter at 'index'
                    temp[index] = islower(temp[index]) ? toupper(temp[index]) : tolower(temp[index]);
                }
            }
            result.push_back(temp);
        }
        
        return result;
    }
};
