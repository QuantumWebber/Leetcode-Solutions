#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int ncr(int n, int r) {
        if (r > n - r) // C(n, r) == C(n, n-r)
            r = n - r;
        long long int res = 1;
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                row.push_back(ncr(i, j));
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};