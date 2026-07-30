class Solution {
private:

    void dfs(int node,int parent,vector<int> adj[],
    vector<int>& disc,vector<int>& low,
    vector<bool>& visited,vector<vector<int>>& ans,int& timer){
        
        
        visited[node]=true;

        
        disc[node]=low[node]=timer++;

        
        for(int nbr:adj[node]){

            // if neighbour is parent, ignore
            // because undirected graph me parent already connected hota hai
            if(nbr==parent) continue;

            // if neighbour not visited
            if(!visited[nbr]){

                // dfs call on neighbour
                // current node becomes parent
                dfs(nbr,node,adj,disc,low,visited,ans,timer);

                // now update low
                // neighbour ke subtree se agar koi back edge mil rahi hogi
                // toh uska low current node me propagate hoga
                low[node]=min(low[node],low[nbr]);

                // bridge condition
                // agar neighbour ka subtree current node se upar
                // kisi ancestor tak nahi ja sakta
                // then current edge is bridge
                if(low[nbr]>disc[node]){
                    ans.push_back({node,nbr});
                }

            }else{
                // back edge case
                // already visited node means cycle mil gaya
                // low ko discovery time se update karo
                low[node]=min(low[node],disc[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

       
        vector<int> adj[n];

        for(auto edges:connections){
            int u=edges[0];
            int v=edges[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        vector<bool> visited(n,false);

        
        vector<int> disc(n,-1);

        
        vector<int> low(n,-1);

       
        vector<vector<int>> ans;

        
        int timer=0;

        
        dfs(0,-1,adj,disc,low,visited,ans,timer);

        return ans;
    }
};