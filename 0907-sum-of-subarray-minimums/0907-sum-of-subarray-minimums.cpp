class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && arr[s.top()] > arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prev = prevSmallerElement(arr, n);
        vector<int> next = nextSmallerElement(arr, n);

        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = (next[i] == -1 ? n : next[i]) - i;
            result = (result + arr[i] * left * right) % MOD;
        }
        return result;
    }
};
