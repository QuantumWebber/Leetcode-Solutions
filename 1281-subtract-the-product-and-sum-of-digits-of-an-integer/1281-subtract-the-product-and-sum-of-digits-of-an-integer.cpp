class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        while (n > 0) {
            int ld = n % 10;
            sum += ld;
            product *= ld;
            n /= 10;
        }
        int difference = product - sum;
        return difference;
    }
};
