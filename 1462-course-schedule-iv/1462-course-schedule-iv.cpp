class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // pre[i][j] = true means i is prerequisite of j
        vector<vector<bool>> pre(numCourses,
                                 vector<bool>(numCourses, false));

        // create graph
        for (auto &p : prerequisites) {

            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;

            pre[p[0]][p[1]] = true;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Kahn's Algorithm
        while (!q.empty()) {

            int front = q.front();
            q.pop();

            for (int nbr : adj[front]) {

                // jo front ke prerequisite the,
                // wo nbr ke bhi prerequisite ban jayenge

                for (int i = 0; i < numCourses; i++) {

                    if (pre[i][front])
                        pre[i][nbr] = true;
                }

                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        vector<bool> result;

        for (auto &q : queries) {
            result.push_back(pre[q[0]][q[1]]);
        }

        return result;
    }
};