// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int s=0 ,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int version=isBadVersion(mid);
            if(version==true) e=mid-1;
            else s=mid+1;
        }
        return s;
        
    }
};