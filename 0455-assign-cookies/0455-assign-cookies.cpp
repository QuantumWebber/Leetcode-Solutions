class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
                sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes


        // yes assuming i will be awesome parent 
        // i need to content my child according to his greed factor and return no of child actually get content 


        int child=0;
        int cookie=0;

        while(child<g.size() && cookie<s.size()){
            if(s[cookie]>=g[child]){
                child++;
            }
            cookie++;
        }
        return child;
    }
};