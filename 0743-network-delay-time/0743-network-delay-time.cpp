class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);

        for (auto &t : times) {
            int u = t[0];
            int v = t[1];
            int wt = t[2];
            adj[u].push_back({v, wt});
        }

        // dijkstra algorithm 
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        set<pair<int,int>> st;
        st.insert({0, k});

        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);              

            int node = it.second;
            int d = it.first;

            for (auto edge : adj[node]) {
                int v = edge.first;
                int wt = edge.second;

                if (d + wt < dist[v]) {
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(dist[i], maxTime);
        }
        return maxTime;
    }
};