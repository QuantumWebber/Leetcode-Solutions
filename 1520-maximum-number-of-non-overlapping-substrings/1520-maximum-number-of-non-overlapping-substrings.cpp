class Solution {
private:

    // first DFS for topological order
    void dfs1(int node, vector<vector<int>>& adj,
              vector<bool>& vis, stack<int>& st) {

        vis[node] = true;

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs1(nbr, adj, vis, st);
            }
        }

        // after finishing, push into stack
        st.push(node);
    }

    // second DFS on reversed graph to collect SCC
    void dfs2(int node, vector<vector<int>>& revAdj,
              vector<bool>& vis, vector<int>& component) {

        vis[node] = true;
        component.push_back(node);

        for (int nbr : revAdj[node]) {
            if (!vis[nbr]) {
                dfs2(nbr, revAdj, vis, component);
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        // store first and last occurrence of each char
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }

        // build dependency graph
        vector<vector<int>> adj(26), revAdj(26);

        for (int c = 0; c < 26; c++) {

            if (last[c] == -1) continue; // character absent

            // traverse interval of character c
            for (int i = first[c]; i <= last[c]; i++) {
                int other = s[i] - 'a';

                if (other != c) {
                    adj[c].push_back(other);
                    revAdj[other].push_back(c);
                }
            }
        }

        // ---------------- Kosaraju Step 1 ----------------
        stack<int> st;
        vector<bool> vis(26, false);

        for (int i = 0; i < 26; i++) {
            if (!vis[i] && last[i] != -1) {
                dfs1(i, adj, vis, st);
            }
        }

        // ---------------- Kosaraju Step 2 ----------------
        fill(vis.begin(), vis.end(), false);

        vector<pair<int,int>> intervals;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {

                vector<int> component;

                // collect one SCC
                dfs2(node, revAdj, vis, component);

                int L = n, R = -1;

                // merge intervals of all chars in SCC
                for (int ch : component) {
                    L = min(L, first[ch]);
                    R = max(R, last[ch]);
                }

                intervals.push_back({L, R});
            }
        }

        // sort by ending index for max non-overlapping
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        // greedy pick non-overlapping intervals
        for (auto &it : intervals) {
            int l = it.first;
            int r = it.second;

            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};