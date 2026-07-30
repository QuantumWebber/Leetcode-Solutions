class Solution {
    private:
    long long int binarySearch(int n){
        long long int s=0;
        long long int e=n;
        long long int ans =-1;

        while(s<=e){
            long long mid=s+(e-s)/2;
            long long square=mid*mid;



            if(square==n)  return mid;
            else if (square<n){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }

           
        }
         return ans;
    }
public:
    int mySqrt(int x) {
       return  binarySearch(x);
    }
};