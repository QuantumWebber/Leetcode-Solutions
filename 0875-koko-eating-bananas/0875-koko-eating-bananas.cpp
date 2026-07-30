class Solution {
private:
    bool canEatInTime(const vector<int>& piles, int h, int speed) {
        int hours = 0;
        for(int pile : piles) {
            hours += (pile + speed - 1) / speed; // this is equivalent to ceil(pile / speed)
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1; // minimum speed can be 1
        int e = *max_element(piles.begin(), piles.end()); // maximum speed can be the size of the largest pile
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (canEatInTime(piles, h, mid)) {
                e = mid; // try a slower speed
            } else {
                s = mid + 1; // try a faster speed
            }
        }
        return s;
    }
};

/* BRUTE FORCE
1. [3,6,7,11]
3/2+6/2+7/2+11/2  so 2 hr not ans try next take ceiling value*/