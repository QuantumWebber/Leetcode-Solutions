class Solution {
    private:
    int reverse(int x){
        long rev=0;
        while(x!=0){
            long digits=x%10;
            rev=rev*10+digits;
            x/=10;
        }
         if(rev>INT_MAX || rev<INT_MIN)  return 0;
        return  int(rev);
    }
public:
    bool isSameAfterReversals(int num) {
        int original=num;
        int rev1=reverse(num);
        int rev2=reverse(rev1);
        if(rev2==original){
            return true;
        }
        return false;
    }
};