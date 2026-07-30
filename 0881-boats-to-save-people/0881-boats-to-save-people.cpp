class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int i=0;
        int n=people.size()-1;
        int boats=0;

        while(i<=n){
            if(people[i]+people[n]<=limit){
                i++;
                n--;
                
            }else{
                n--;
            }
            boats++;
        }
        return boats;
    }
};