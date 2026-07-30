class Solution {
public:
   int sumOfPower(vector<int>& nums) {
    long long mod = 1e9 + 7, pre = 0, res = 0;
    sort(nums.begin(), nums.end());   // important step

    for (long long x: nums) {
        // For current element x (used as max in subsequence)
        // res += x^3 + x^2 * sum of all subsets before x
        res = (res + (x * x % mod) * x % mod + (x * x % mod) * pre % mod) % mod;

        // Update sum of all subsets that can be made before this x
        pre = (pre * 2 + x) % mod;
    }
    return res;
}
};