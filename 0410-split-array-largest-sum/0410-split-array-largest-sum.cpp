#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(), nums.end());  // Min capacity (largest element)
        int e = accumulate(nums.begin(), nums.end(), 0); // Max capacity (sum of all elements)

        int ans = e;  // Answer will always be within this range
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int subCount = 1, subSum = 0;

            for (int num : nums) {
                if (subSum + num <= mid) {
                    subSum += num;  // Keep adding to the current subarray
                } else {
                    subCount++;     // Create a new subarray
                    subSum = num;   // Start with this element
                }
            }

            if (subCount > k) {  // More splits than needed → Increase sum limit
                s = mid + 1;
            } else {  // Valid or excessive splits → Try to minimize `mid`
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
};

