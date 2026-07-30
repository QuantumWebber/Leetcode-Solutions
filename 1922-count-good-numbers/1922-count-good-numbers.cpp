class Solution {

    private:
    const int mod = 1e9 + 7;

    long long power(long long x, long long n) {
        if(n==0)  return 1;

        long long temp=power(x,n/2);

        if(n%2==0) return (temp*temp)%mod;

        else return (x*temp*temp)%mod;
        
        }
public:

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        long long res = (power(5, evenCount) * power(4, oddCount)) % mod;
        return (int)res;
    }
};


// brute force approach of mine 
/*class Solution {
private:
    bool goodNumbers(long long n, int length){
        for(int i=0; i<length; i++){
            int digit = n % 10;
            n /= 10;

            if(i % 2 == 0){ // even index (from right)
                if(digit % 2 != 0) return false;
            } else { // odd index (from right)
                if(digit != 2 && digit != 3 && digit != 5 && digit != 7)
                    return false;
            }
        }
        return true;
    }

public:
    int countGoodNumbers(long long n) {
        int lower = (n == 1) ? 0 : pow(10, n - 1);
        int upper = pow(10, n) - 1;

        int count = 0;
        for(long long i = lower; i <= upper; i++){
            if(goodNumbers(i, n)){
                count++;
            }
        }
        return count;
    }
};*/