class Solution {
public:
    void reverse(vector<int>& nums, int s, int e) {
        while (s < e) {
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is larger than n
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int max_ans = INT_MIN;
        int current_ans = 0;
        int sum = 0;

        // Calculate the sum of all elements in nums and the initial value of F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            current_ans += i * nums[i];
        }

        max_ans = current_ans;

        // Calculate F(i) for each rotation
        for (int i = 1; i < n; i++) {
            current_ans = current_ans + sum - n * nums[n - i];
            max_ans = max(max_ans, current_ans);
        }

        return max_ans;
    }
};
