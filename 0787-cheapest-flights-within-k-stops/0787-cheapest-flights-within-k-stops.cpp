class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //  dist[] array -- har city tak abhi tak ka best  price
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; 

        // k+1 rounds chalao
       
        for (int i = 0; i <= k; i++) {

            
            vector<int> temp = dist;

            
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], price = flight[2];

                
                if (dist[u] == INT_MAX) continue;

                // agar u tak jaake, phir v tak is flight se jaana,
                // pichle best price se sasta padta hai -- to update 
                if (dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }

            
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};