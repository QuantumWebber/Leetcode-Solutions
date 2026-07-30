class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx1 = -1, idx2 = -1;

        // Step 1: Find the largest index idx1 such that nums[idx1] < nums[idx1 + 1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx1 = i;
                break;
            }
        }

        // If no such idx1 is found, the array is sorted in descending order, reverse it to get the smallest permutation
        if (idx1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the largest index idx2 such that nums[idx2] > nums[idx1]
        for (int i = n - 1; i > idx1; i--) {
            if (nums[i] > nums[idx1]) {
                idx2 = i;
                break;
            }
        }

        // Step 3: Swap nums[idx1] and nums[idx2]
        swap(nums[idx1], nums[idx2]);

        // Step 4: Reverse the sequence from idx1 + 1 to the end of the array
        reverse(nums.begin() + idx1 + 1, nums.end());
    }
};

/* 1. generate all permuatation 
2. get sorted make linear search and go for next one
time complexity o(n!*n)*/