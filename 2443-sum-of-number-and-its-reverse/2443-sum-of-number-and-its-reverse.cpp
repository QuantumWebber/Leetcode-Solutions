class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; ++i) {
            int x = i;
            int y = 0;
            while (x != 0) {
                int rem = x % 10;
                y = y * 10 + rem;
                x /= 10;
            }
            if (i + y == num) return true;
        }
        return false;
    }
};