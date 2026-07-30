class Solution {
private:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(n); // use n instead of -1 for easier calculations
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            while(s.top() != n && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            while(s.top() != -1 && arr[s.top()] > arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(n); // use n instead of -1
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            while(s.top() != n && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            ans[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            while(s.top() != -1 && arr[s.top()] < arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    long long sumOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = prevSmallerElement(arr, n);
        vector<int> next = nextSmallerElement(arr, n);

        long long result = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            result += (long long)arr[i] * left * right;
        }
        return result;
    }

    long long sumOfMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev = prevGreaterElement(arr, n);
        vector<int> next = nextGreaterElement(arr, n);

        long long result = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            result += (long long)arr[i] * left * right;
        }
        return result;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMaxs(nums) - sumOfMins(nums);
    }
};
