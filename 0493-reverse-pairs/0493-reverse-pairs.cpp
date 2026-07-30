
class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r, int& reversePairCount) {
        int an = mid - l + 1;
        int bn = r - mid;
        vector<int> a(an), b(bn);

        for (int i = 0; i < an; i++) {
            a[i] = arr[l + i];
        }
        for (int j = 0; j < bn; j++) {
            b[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = l;

        // Count reverse pairs
        for (int i = 0, j = 0; i < an; ++i) {
            while (j < bn && a[i] > 2L * b[j]) {
                ++j;
            }
            reversePairCount += j;
        }

        i = 0;
        j = 0;

        // Merge two sorted arrays
        while (i < an && j < bn) {
            if (a[i] <= b[j]) {
                arr[k++] = a[i++];
            } else {
                arr[k++] = b[j++];
            }
        }

        while (i < an) {
            arr[k++] = a[i++];
        }
        while (j < bn) {
            arr[k++] = b[j++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r, int& reversePairCount) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid, reversePairCount);
            mergeSort(arr, mid + 1, r, reversePairCount);
            merge(arr, l, mid, r, reversePairCount);
        }
    }

    int reversePairs(vector<int>& nums) {
        int reversePairCount = 0;
        mergeSort(nums, 0, nums.size() - 1, reversePairCount);
        return reversePairCount;
    }
};