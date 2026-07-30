class Solution {
    private:
    vector<int> merge(vector<int>& num1, vector<int>& num2) {
        int m = num1.size();
        int n = num2.size();
        int i = 0, j = 0, k = 0;
        vector<int> arr(m + n);
        while (i < m && j < n) {
            if (num1[i] < num2[j]) {
                arr[k++] = num1[i++];
            } else {
                arr[k++] = num2[j++];
            }
        }
        while (i < m) {
            arr[k++] = num1[i++];
        }
        while (j < n) {
            arr[k++] = num2[j++];
        }
        return arr;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged=merge(nums1,nums2);
        int n=merged.size();

        if(n%2==0){
            return ( merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }else{
            return merged[n/2];
        }

    }
};