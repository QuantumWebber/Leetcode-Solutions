class Solution {
    private:
    const int mod=1e9+7;
    long long power(long long x,long long n){
        if (n==0)  return 1;
        long long temp=power(x,n/2);
        if(n%2==0)  return (temp*temp)%mod;
        else return (x*temp*temp)%mod;
    }

public:
    int monkeyMove(int n) {


        return (int)(power(2,n)-2+mod)%mod;
    }
};

//movement of monkey clockwise (i+1)%n
// in anticlockwise (i-1+n)%n

// n=3 i=0 index wala monkey (1)%3=1 while anticlockwise (3)%3=0
//total movement is 2^n ase tarike jisse atleast one collision ho 2^n-2 2 kya wo jisse ek bhi movement nhi hogi one is completley clockwise or anticlockwise